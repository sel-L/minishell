# Minishell AI Agent Instructions

## Project Overview
A POSIX shell implementation in C (42 school project) with tokenization → parsing → AST → execution pipeline.

## Architecture (Current State: Parsing Branch)

### Core Pipeline
1. **Tokenization** (`src/tokenize/`, `headers/tokenize.h`)
   - Converts input strings into linked list of `t_token` nodes
   - Token types: `WORD`, `PIPE`, `REDIR_IN` (`<`), `REDIR_OUT` (`>`), `APPEND` (`>>`), `HERE_DOC` (`<<`)
   - Current implementation uses `ft_split` (needs char-by-char lexer for quote handling)

2. **Validation** (`src/parsing/redir_check.c`)
   - Validates token sequences before AST construction
   - Key rules: redirections must have WORD targets, no adjacent pipes, no leading/trailing pipes

3. **AST Construction** (planned, see `headers/ast.h`)
   - Will use precedence climbing for operator precedence
   - Node types: `AST_CMD` (simple command + redirections), `AST_PIPE` (binary operator)

4. **Execution** (not yet implemented)
   - Tree-walk interpreter: process AST nodes recursively
   - Handle pipes with fork/dup2, redirections with open/dup2

### Data Structures

**Token (`t_token` in `tokenize.h`)**
```c
typedef struct s_token {
    char            *value;
    t_token_type    type;
    struct s_token  *next;
} t_token;
```

**Environment List (`t_env_list` in `m_env.h`)**
```c
typedef struct s_env_list {
    char                *env_val;  // "KEY=value" format
    struct s_env_list   *next;
} t_env_list;
```

## Critical Patterns

### Linked List Memory Management
**Always use temp pointer when freeing**:
```c
void free_list(t_node *head) {
    t_node *temp;
    while (head) {
        temp = head->next;  // Save next BEFORE freeing
        free(head->data);
        free(head);
        head = temp;
    }
}
```
Wrong: `while (head->next)` skips last node; `head = head->next` after `free(head)` is use-after-free.

### Appending to Linked Lists
Always traverse to tail, don't just append to `head->next`:
```c
if (*list == NULL)
    *list = new_node;
else {
    last = *list;
    while (last->next)
        last = last->next;
    last->next = new_node;
}
```

### Token Validation Pattern
Single-pass with cursor advancement checking current and next tokens (`src/parsing/redir_check.c`):
- Check `is_redir(cur->type)` → ensure `cur->next && cur->next->type == WORD`
- Check `cur->type == PIPE` → ensure `cur->next && cur->next->type != PIPE`
- Validate first and last tokens separately

## Build System

**Makefile structure**:
- Main binary: `minishell` (links libft + readline)
- Libft: recursive make in `libft/`
- Source directories: `src/parsing/` and `src/tokenize/`
- **Don't** recursively call make in subdirectories that don't have main—causes "undefined reference to main"

**Build commands**:
```bash
make          # compile minishell
make clean    # remove objects
make fclean   # full clean (removes binary)
make re       # rebuild from scratch
```

## Development Workflow

**Test harness** (`src/parsing/test.c`):
- Readline loop with history
- Calls `tokenize()` → `validator()` → prints result
- To add AST: insert `parse_command_line(&tokens)` after validation

**Common Issues**:
- Segfault on second command: forgot to initialize `tokens = NULL` before loop
- Validator false negatives: checking wrong token (head vs. cursor), or incomplete `is_redir()` (missing `HERE_DOC`)
- Makefile link errors: subdir Makefile trying to link without main

## Next Implementation Steps (Priority Order)

1. **Robust lexer**: Replace `ft_split` with char-by-char tokenizer that handles:
   - Quotes (`'...'` no expansion, `"..."` allows `$VAR`)
   - Operators without whitespace (`echo a>out` → 4 tokens)
   - Heredoc delimiter quoting state

2. **Heredoc collection**: After tokenization, before execution:
   - Read lines until delimiter (use readline)
   - Expand variables only if delimiter unquoted
   - Store in temp file or buffer

3. **AST parser**: Precedence climbing (`PIPE` at precedence 10, left-assoc):
   - `parse_simple_command()`: collect WORDs into argv, attach redirections
   - `parse_expr(min_prec)`: climb through binary operators

4. **Executor**: Tree-walk with node type dispatch:
   - `AST_CMD`: setup redirections, fork/execve or builtin
   - `AST_PIPE`: create pipe, fork left and right, connect fds

## 42 School Conventions

- Use 42 header with norminette compliance (25-line functions, 80-char lines, no for loops)
- All headers in `headers/`, sources in `src/`
- Custom libft in `libft/` subdirectory
- No global variables (except signal-related single int if needed)

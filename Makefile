# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 10:47:03 by wshou-xi          #+#    #+#              #
#    Updated: 2025/12/04 00:45:20 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iheaders -I./libft/includes
LIB = -lreadline -lhistory -Llibft -lft
RM = rm -rf
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --verbose

MAINDIR =
MAINFILES =
MAIN = $(addprefix $(MAINDIR)/, $(MAINFILES))

PARSEDIR = src/parsing
PARSEFILES = main.c redir_check.c
PARSE = $(addprefix $(PARSEDIR)/, $(PARSEFILES))

ARGVDIR = src/argv
ARGVFILES = argv_to_node.c argv_utils.c tok_conv.c
ARGV = $(addprefix $(ARGVDIR)/, $(ARGVFILES))

TOKENDIR = src/tokenize
TOKENFILES = tokenize_add_token.c tokenize_detect.c tokenize_free.c \
			tokenize_init.c tokenize_print_tokens.c tokenize.c
TOKEN = $(addprefix $(TOKENDIR)/, $(TOKENFILES))

ENVDIR = src/env
ENVFILES = env_init.c env_op.c env_utils.c env_var_utils.c env_vars.c
ENV = $(addprefix $(ENVDIR)/, $(ENVFILES))

SRC = $(MAIN) $(TOKEN) $(ENV) $(PARSE) $(ARGV)
OBJDIR = obj
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

VPATH = $(MAINDIR) $(TOKENDIR) $(ENV)

NAME = minishell

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -s -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo Minishell successfully compiled

clean:
	@$(MAKE) -s -C libft clean
	@$(RM) $(OBJDIR)

fclean: clean
	@$(MAKE) -s -C libft fclean
	@$(RM) $(NAME)
	@echo Successfully full cleaned

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re

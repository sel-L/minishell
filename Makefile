# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 10:47:03 by wshou-xi          #+#    #+#              #
#    Updated: 2025/11/23 19:36:55 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iheaders -I./libft/includes
LIB = -lreadline -lhistory -Llibft -lft
RM = rm -rf

MAINDIR = src/parsing
MAINFILES = test.c redir_check.c env_var.c env_var_utils.c
MAIN = $(addprefix $(MAINDIR)/, $(MAINFILES))

TOKENDIR = src/tokenize
TOKENFILES = tokenize_add_token.c tokenize_detect.c tokenize_free.c \
			tokenize_init.c tokenize_print_tokens.c tokenize.c
TOKEN = $(addprefix $(TOKENDIR)/, $(TOKENFILES))

SRC = $(MAIN) $(TOKEN)
OBJDIR = obj
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

VPATH = $(MAINDIR) $(TOKENDIR)

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

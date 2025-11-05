/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wee <wee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:41:54 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/05 22:31:36 by wee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

# define METACHARACTERS " |&;()<>"

# include "minishell.h"

typedef struct	s_token
{
	char			*token;
	int				size;
	struct s_token	*next;
}				t_token;

typedef struct	s_lexer
{
	char	*start;
	char	*end;
	int	quote;
}				t_lexer;

typedef enum t_quotes
{
	NO_QUOTE,
	QUOTE,
}			s_quote;

int		check_m_char(char str);
t_token	*new_node(char *str);
void	tokenizer(char *str);
void	tokadd_back(t_token **lst, t_token *new);
void	add_token(t_token **token, char *str);
void	create_token(t_token **token, char *str);

#endif
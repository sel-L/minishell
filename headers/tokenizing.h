/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:41:54 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/02 15:25:52 by wshou-xi         ###   ########.fr       */
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
	int	start;
	int	end;
	int	size;
	int	quote_flag;
}				t_lexer;

int		check_m_char(char str);
t_token	*new_node(char *str);
t_token	**tokenizer(char *str);
void	tokadd_back(t_token **lst, t_token *new);
void	add_token(t_token **token, char *str);


#endif
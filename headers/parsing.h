/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:47:09 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/02 16:21:29 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "tokenize.h"
# include "m_env.h"

typedef struct	s_parsing
{
	t_env_list	*env_list;
	t_token		*token;
}				t_parsing;

int		validator(t_token *token);
char	**tok_to_argv(t_token *token);
int		tok_size(t_token *token);
void	print_str_arr(char **str_arr);
void	free_argv(char **argv);

#endif
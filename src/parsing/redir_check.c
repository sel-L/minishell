/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:17:14 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/22 18:39:27 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

int	redir_val(t_token *token);

int	validator(t_token *token)
{
	if (!token)
		return (1);
	if (redir_val(token) == 1)
		return (perror("syntax error near unexpected token"), 1);
	return (0);
}

int	is_redir(t_token_type t)
{
	return (t == REDIR_IN || t == REDIR_OUT || t == APPEND || t == PIPE);
}

int	pipe_val(t_token *curr_token, t_token *next_token)
{
	if (curr_token->type == PIPE)
	{
		if (!next_token)
			return (1);
		if (next_token->type == PIPE)
			return (1);
		if (next_token->type != WORD)
			return (1);
	}
	if (next_token->type == PIPE)
	{
		if (!next_token->next)
			return (1);
	}
	return (0);
}

int	redir_val(t_token *token)
{
	t_token	*curr_token;
	t_token	*next_token;

	if (!token || token->type == PIPE)
		return (1);
	curr_token = token;
	if (!token->next)
		curr_token->next = NULL;
	next_token = curr_token->next;
	while (next_token)
	{
		if (is_redir(token->type))
		{
			if (!next_token || next_token->type != WORD)
				return (1);
		}
		if (!next_token || (token->type == PIPE && next_token->type == PIPE))
			return (1);
		curr_token = token->next;
		next_token = curr_token->next;
	}
	if (is_redir(token->type) && !next_token)
		return (1);
	return (0);
}

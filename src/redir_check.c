/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:17:14 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/15 16:27:24 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

int	redir_val(t_token *token);

int	validator(t_token *token)
{
	if (!token)
		return (0);
	if (!redir_val(token))
		return (0);
}

int	redir_val(t_token *token)
{
	t_token	*next_token;

	if (!token)
		return (0);
	next_token = token->next;
	if (token->type == REDIR_IN || token->type == REDIR_OUT)
	{
		if (next_token->type != WORD)
			return (0);
	}
	return (1);
}
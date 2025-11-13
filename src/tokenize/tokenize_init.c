/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:03:43 by joloo             #+#    #+#             */
/*   Updated: 2025/11/13 12:58:23 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_internal.h"

int	tokenize_init(t_tok *data, char *input)
{
	ft_memset(data, 0, sizeof(data));
	if (init_lookup(data) == FAILIURE)
		return (FAILURE);
}

int	init_lookup(t_tok *data)
{
	data->token_lookup = malloc(sizeof(char *) * (WORD));
	if (data->token_lookup == NULL)
	{
		printf("data->token_lookup Malloc failure\n");
		return (FAILURE);
	}
	data->token_lookup[HERE_DOC] = ft_strdup("<<");
	data->token_lookup[APPEND] = ft_strdup(">>");
	data->token_lookup[REDIR_IN] = ft_strdup("<");
	data->token_lookup[REDIR_OUT] = ft_strdup(">");
	data->token_lookup[PIPE] = ft_strdup("|");
	data->token_lookup[WORD] = NULL;
	return (SUCCESS);
}

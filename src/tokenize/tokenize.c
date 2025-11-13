/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:38:46 by joloo             #+#    #+#             */
/*   Updated: 2025/11/13 13:09:44 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_internal.h"

// parameter is string directly from readline
// returns a linked list of tokens
// returns NULL on error
t_token	*tokenize(char *input)
{
	t_tok	data;
	int		i;

	if (tokenize_init(&data, input) == FAILURE)
		return (NULL);
	i = 0;
	while (1)
	{
		while (data.input[i] != '\0'
			&& ft_isspace(data.input[i]) == TRUE)
			i++;
		if (data.input[i] == '\0')
			break ;
		if (tokenize_extract(&data, &i) == 0)
		{
			tokenize_free(&data);
			return (NULL);
		}
	}
	tokenize_free(&data);
	return (head);
}

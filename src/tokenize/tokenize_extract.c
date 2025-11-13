/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_extract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:09:34 by joloo             #+#    #+#             */
/*   Updated: 2025/11/13 14:57:49 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_internal.h"

int	tokenize_process(t_tok *data, int *i)
{
	int	type;

	type = detect_type(data, *i);
	return (SUCCESS);
}

int	detect_type(t_tok *data, int i)
{
	int	type;

	type = 0;
	while (data->token_lookup[type] != NULL)
	{
		if (ft_strncmp(data->input + i, data->token_lookup[type],
				ft_strlen(data->token_lookup[type])) == 0)
			return (type);
		type++;
	}
	return (WORD);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_argv_tokenize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:40:18 by joloo             #+#    #+#             */
/*   Updated: 2025/11/27 16:46:52 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_argv_internal.h"

int	expansion_argv_tokenize(t_exp_argv_data *data)
{
	int	i;

	i = 0;
	while(data->argv[i] != NULL)
	{
		if (expansion_argv_tokenize_process(data, data->argv[i]) == FAILURE)
			return (FAILURE);
		if (add_node(data, NULL, 0, DELIMITER) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	expansion_argv_tokenize_process(t_exp_argv_data *data, char *str)
{
	int	j;

	j = 0;
	detect_quotes(str[j], &data->in_squote, &data->in_dquote);
	while (str[j] != '\0')
	{
		if (data->in_squote != TRUE)
		{
			if (data[j] == '$')
			{
				if (add_var(data, str, &j) == FAILURE)
					return (FAILURE);
				continue ;
			}
		}
		if (add_word(data, str, &j) == FAILURE)
			return (FAILURE);
	}
	data->in_squote = 0;
	data->in_dquote = 0;
	return (SUCCESS);
}

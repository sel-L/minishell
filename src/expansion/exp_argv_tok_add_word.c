/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_argv_tok_add_word.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:35:50 by joloo             #+#    #+#             */
/*   Updated: 2025/12/05 16:06:08 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_argv_internal.h"

int	add_word(t_exp_argv_data *data, char *str, int *j)
{
	int	k;

	k = 0;
	while (str[*j + k] != '\0')
	{
		if (data->in_squote == FALSE)
		{
			if (str[*j + k] == '$')
				break ;
		}
		k++;
		detect_quotes(str[*j + k], &data->in_squote, &data->in_dquote);
	}
	if (k > 0)
	{
		if (add_node(data, str + *j, k, WORD) == FAILURE)
			return (FAILURE);
		*j += k;
	}
	return (SUCCESS);
}

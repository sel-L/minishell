/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_argv_tok_add_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:19:41 by joloo             #+#    #+#             */
/*   Updated: 2025/12/04 15:03:40 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_argv_internal.h"

int	add_var(t_exp_argv_data *data, char *str, int *j)
{
	int	k;

	k = 1;
	if (data->in_dquote == TRUE)
		data->type = DOUBLE_QUOTED_VAR;
	else
		data->type = VAR;
	while (str[*j + k] != '\0' && ft_isspace(str[*j + k]) == FALSE)
	{
		detect_quotes(str[j], &data->in_squote, &data->in_dquote);
		if (data->type == DOUBLE_QUOTED_VAR)
		{
			if (data->in_dquote == FALSE)
				break ;
		}
		if (data->type == VAR)
		{
			if (data->in_squote == TRUE || data->in_dquote == TRUE)
				break ;
		}
		k++;
	}
	if (add_var_node, data, str, j, k) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	add_var_node(t_exp_argv_data *data, char *str, int *j, int k)
{
	if (k == 1)
	{
		if (add_node(data, str + *j, k, WORD) == FAILURE)
			return (FAILURE);
		*j += k;
	}
	if (k > 1)
	{
		if (add_node(data, str + *j, k, data->type) == FAILURE)
			return (FAILURE);
		*j += k;
	}
	return (SUCCESS);
}

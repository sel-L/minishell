/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_argv_tokenize.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:40:18 by joloo             #+#    #+#             */
/*   Updated: 2025/11/26 17:09:01 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_argv_internal.h"

int	expansion_argv_tokenize(t_exp_argv_data *data)
{
	int	i;

	i = 0;
	while(data->argv[i] != NULL)
	{
		i++;
	}
	return (SUCCESS);
}

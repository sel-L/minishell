/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:26:02 by joloo             #+#    #+#             */
/*   Updated: 2025/11/26 17:05:43 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_argv_internal.h"

char **expand_argv(char **argv, t_env_list *env)
{
	t_exp_argv_data data;
	ft_memset(&data, 0, sizeof(t_exp_argv_data));
	data.argv = argv;
	data.env = env;
	if (expansion_argv_tokenize(&data) == FAILURE)
		return (expand_argv_free(&data), NULL);
	return (data.res);
}

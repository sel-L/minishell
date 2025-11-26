/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:26:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/26 18:22:37 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include <readline/readline.h>

int	main(int ac, char **av, char **envp)
{
	t_env_list	*env_list;
	char		**temp;
	int			i;

	(void)ac;
	(void)av;
	env_list = env_to_list(envp);
	add_env("A=10", &env_list);
	temp = list_to_char(&env_list);
	i = 0;
	while (temp[i])
	{
		printf("%s\n", temp[i]);
		i++;
	}
	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free_env(env_list);
	free(temp);
	return (0);
}
 
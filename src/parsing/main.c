/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/29 14:19:37 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

int	main(int ac, char **av, char **envp)
{
	t_token		*tokens;
	t_env_list	*env;
	char	*str;

	(void)ac;
	(void)av;
	env = env_to_list(envp);
	print_env(env);
	free_env(env);
	while (1)
	{
		str = readline("line here$ ");
		add_history(str);
		if (*str == '\0' || str == NULL || *str == 32)
			continue ;
		tokens = tokenize(str);
		printf("%d\n", validator(tokens));
		free (tokens);
	}
	return (0);
}
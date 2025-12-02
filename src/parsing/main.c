/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/02 17:57:29 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

char	**parsing(char *input, t_env_list *env)
{
	t_token		*token;
	char		**argv;

	if (!input || !env)
		return (NULL);
	token = tokenize(input);
	if (validator(token) != 0)
		return (printf("1\n"), free_tokens(&token), NULL);
	argv = tok_to_argv(token);
	if (!argv)
		return (NULL);
	free_tokens(&token);
	return (argv);
}

int main(int ac, char **av, char **envp)
{
	t_env_list	*env;
	char		*str;
	char		**res;

	(void)ac;
	(void)av;
	env = env_to_list(envp);
	while (1)
	{
		str = readline("line here$ ");
		add_history(str);
		if (*str == '\0' || str == NULL || *str == 32)
			continue;
		res = parsing(str, env);
		if (res == NULL)
			return (ft_free_str_arr(res), free_env(env), 1);
		free_argv(res);
	}
	free_env(env);
}

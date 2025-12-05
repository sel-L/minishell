/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/05 18:16:51 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

char	**parsing(char *input, t_env_list *env)
{
	t_token	*token;
	t_node	*node;
	char	**argv;

	if (!input || !env)
		return (printf("no input\n"), NULL);
	token = tokenize(input);
	if (validator(token) != 0)
		return (printf("1\n"), free_tokens(&token), NULL);
	argv = tok_to_argv(token);
	if (!argv)
		return (printf("invalid argv\n"), NULL);
	node = token_to_node(token);
	print_node(node);
	free_node(node);
	free_tokens(&token);
	print_str_arr(argv);
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
	if (!env)
		printf("env failed\n");
	while (1)
	{
		str = readline("> ");
		add_history(str);
		if (str == NULL || *str == '\0' || *str == 32)
			continue;
		res = parsing(str, env);
		if (res == NULL)
			return (ft_free_str_arr(res), free_env(env), 1);
		free_argv(res);
	}
	free_env(env);
	return (0);
}

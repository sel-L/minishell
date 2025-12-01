/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/01 09:11:08 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

char	**parsing(char *input, t_env_list *env)
{
	t_token		*token;
	int			(*f)(t_token *) = validator;

	if (!input || !env)
		return (NULL);
	token = tokenize(input);
	if (f(token) == 1)
		return (free_tokens(token), NULL);
}

int main(int ac, char **av, char **envp)
{
	t_token *tokens;
	t_env_list *env;
	char *str;

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
			continue;
		tokens = tokenize(str);
		printf("%d\n", validator(tokens));
		free(tokens);
	}
	return (0);
}
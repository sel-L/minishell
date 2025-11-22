/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:26:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/23 02:34:41 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include <readline/readline.h>

void	free_env(t_env_list *env_list)
{
	t_env_list *temp;

	while (env_list)
	{
		temp = env_list->next;
		free(env_list->env_val);
		free(env_list);
		env_list = temp;
	}
	return ;
}

int	add_env_list(char *env, t_env_list **list)
{
	t_env_list	*m_env;
	static t_env_list	*last;

	m_env = malloc(sizeof(t_env_list));
	if (!m_env)
		return (1);
	m_env->env_val = ft_strdup(env);
	if (!m_env->env_val)
		return (free(m_env), 1);
	m_env->next = NULL;
	if (*list == NULL)
		*list = m_env;
	else
	{
		if (last == NULL)
			last = *list;
		while (last->next)
			last = last->next;
		last->next = m_env;
	}
	return (0);
}

t_env_list	*env_to_list(char **env)
{
	t_env_list	*env_list;
	int			i;

	env_list = NULL;
	if (!env || !*env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (add_env_list(env[i], &env_list) == 1)
			free_env(env_list);
		i++;
	}
	return (env_list);
}

void	print_env(char **envp)
{
	t_env_list	*env;
	t_env_list	*head;
	int			i = 0;

	env = env_to_list(envp);
	if (!env)
		return ;
	head = env;
	while (env)
	{
		printf("env %d is %s\n", i, env->env_val);
		env = env->next;
		i++;
	}
	free_env(head);
	return ;
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	print_env(envp);
	return (0);
}
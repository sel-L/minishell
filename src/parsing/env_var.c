/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:26:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/26 15:50:01 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include <readline/readline.h>

/// @brief create a env node with the content and add it to the back of the list
/// @param env 
/// @param list 
/// @return 0 for success 1 for error
int	add_env(char *env, t_env_list **list)
{
	t_env_list	*m_env;
	char		*temp;

	m_env = malloc(sizeof(t_env_list));
	if (!m_env)
		return (1);
	temp = env;
	while (*env != '=')
		env++;
	m_env->front = ft_substr(temp, 0, (env - temp));
	m_env->env_val = ft_substr(env, 1, (ft_strlen(env)));
	if (!m_env->front || !m_env->env_val)
		return (free(m_env->front), free(m_env->env_val), 1);
	if (find_env_front(m_env->front, list) != NULL)
	{
		change_value(temp, list);
		return (free(m_env->front), free(m_env->env_val), free(m_env), 0);
	}
	m_env->next = NULL;
	m_env->prev = NULL;
	return (add_env_node(m_env, list));
}

/// @brief 
/// @param target 
/// @param list 
/// @return 
int	remove_env(char *target, t_env_list **list)
{
	t_env_list	*curr;
	t_env_list	*prev;

	curr = *list;
	if (ft_strcmp(target, (*list)->env_val) == 0)
		return (delete_node(list), free(target), 0);
	prev = curr;
	curr = curr->next;
	while (curr)
	{
		if (ft_strcmp(target, curr->front) == 0)
		{
			prev->next = curr->next;
			if (curr->next)
				curr->next->prev = prev;
			return (delete_node(&curr), free(target), 0);
		}
		prev = curr;
		curr = curr->next;
	}
	return (free (target), 1);
}

/// @brief loop through the envp from main and call add_env_list
/// @param env 
/// @return env linked list
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
		if (add_env(env[i], &env_list) == 1)
			return (free_env(env_list), NULL);
		i++;
	}
	return (env_list);
}

char	**list_to_char()

void	print_env(t_env_list *env)
{
	if (!env)
		return ;
	while (env)
	{
		printf("%s\n", env->env_val);
		env = env->next;
	}
	return ;
}

int	main(int ac, char **av, char **envp)
{
	t_env_list	*env_list;

	(void)ac;
	(void)av;
	env_list = env_to_list(envp);
	remove_env("SHELL", &env_list);
	add_env("A=10", &env_list);
	// print_env(env_list);
	// printf("\n\n\n");
	remove_env("A", &env_list);
	print_env(env_list);
	free_env(env_list);
	return (0);
}
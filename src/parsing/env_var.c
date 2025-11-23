/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:26:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/24 00:56:02 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include <readline/readline.h>
/// @brief free entire env list
/// @param env_list 
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
/// @brief create a env node with the content and add it to the back of the list
/// @param env 
/// @param list 
/// @return 0 for success 1 for error
int	add_env(char *env, char *temp,t_env_list **list)
{
	t_env_list			*m_env;
	static t_env_list	*last;

	m_env = malloc(sizeof(t_env_list));
	if (!m_env)
		return (1);
	temp = env;
	while (*env != '=')
		env++;
	m_env->front = ft_substr(temp, 0, (env - temp) + 1);
	m_env->env_val = ft_substr(env, 1, (ft_strlen(env)));
	if (!m_env->env_val)
		return (free(m_env), 1);
	m_env->next = NULL;
	if (*list == NULL)
		return ((*list = m_env), 0);
	if (last == NULL)
		last = *list;
	while (last->next)
		last = last->next;
	last->next = m_env;
	return (0);
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
	if (ft_strcmp(target, curr->front) == 0)
		return (delete_node(list), 0);
	prev = curr;
	curr = curr->next;
	while (curr)
	{
		if (ft_strcmp(target, curr->front) == 0)
		{
			prev->next = curr->next;
			if (curr->next)
				curr->next->prev = prev;
			return (delete_node(&curr), 0);
		}
		prev = curr;
		curr = curr->next;
	}
	return (1);
}

/// @brief loop through the envp from main and call add_env_list
/// @param env 
/// @return env linked list
t_env_list	*env_to_list(char **env)
{
	t_env_list	*env_list;
	t_env_list	*curr;
	int			i;

	env_list = NULL;
	if (!env || !*env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (add_env(env[i], env[i], &env_list) == 1)
			free_env(env_list);
		i++;
	}
	curr = env_list;
	curr->prev = NULL;
	while(curr->next)
	{
		curr->next->prev = curr;
		curr = curr->next;
	}
	return (env_list);
}

void	print_env(t_env_list *env)
{
	t_env_list	*head;

	if (!env)
		return ;
	head = env;
	while (env)
	{
		printf("%s%s\n", env->front, env->env_val);
		env = env->next;
	}
	free_env(head);
	return ;
}

int	main(int ac, char **av, char **envp)
{
	t_env_list	*env_list;

	(void)ac;
	(void)av;
	env_list = env_to_list(envp);
	remove_env("SHLVL=", &env_list);
	add_env()
	print_env(env_list);
	return (0);
}
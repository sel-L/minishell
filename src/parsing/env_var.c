/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:26:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/25 18:39:54 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include <readline/readline.h>

int	change_value(char *src, t_env_list **list)
{
	t_env_list	*temp;
	int			len;
	char		*front;
	char		*ori;

	if (!src || !list || !*list)
		return (1);
	ori = src;
	len = 0;
	while(src[len] && src[len] != '=')
		len++;
	front = ft_substr(ori, 0, len + 1);
	temp = find_env_front(ori, list);
	free (temp->env_val);
	temp->env_val = ft_substr(src, len + 1, ft_strlen(src) - len - 1);
	return (free(front), 0);
}

int	add_env_node(t_env_list *node ,t_env_list **list)
{
	t_env_list	*last;

	if (*list == NULL)
		return ((*list = node), 0);
	node->next = NULL;
	node->prev = NULL;
	last = *list;
	while (last->next)
		last = last->next;
	last->next = node;
	node->prev = last;
	return (0);
}

/// @brief create a env node with the content and add it to the back of the list
/// @param env 
/// @param list 
/// @return 0 for success 1 for error
int	add_env(char *env, t_env_list **list)
{
	t_env_list			*m_env;
	char				*temp;

	m_env = malloc(sizeof(t_env_list));
	temp = env;
	while (*env != '=')
		env++;
	m_env->front = ft_substr(temp, 0, (env - temp) + 1);
	m_env->env_val = ft_substr(env, 1, (ft_strlen(env)));
	if (find_env_front(m_env->front, list) != NULL)
		return (change_value(env, list), 0);
	if (!m_env->env_val)
		return (free(m_env->front), free(m_env), 1);
	m_env->next = NULL;
	m_env->prev = NULL;
	if (*list == NULL)
		return ((*list = m_env), 0);
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
	target = ft_strjoin(target, "=");
	if (ft_strcmp(target, curr->front) == 0)
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
	free (target);
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
		if (add_env(env[i], &env_list) == 1)
			return (free_env(env_list), 1);
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
	if (!env)
		return ;
	while (env)
	{
		printf("%s%s\n", env->front, env->env_val);
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
	print_env(env_list);
	printf("\n\n\n");
	add_env("A=20", &env_list);
	print_env(env_list);
	free_env(env_list);
	return (0);
}
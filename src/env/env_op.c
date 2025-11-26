/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:35:25 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/26 16:39:19 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

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
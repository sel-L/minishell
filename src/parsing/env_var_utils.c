/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:12:12 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/24 00:38:32 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

t_env_list	*find_env_front(char *to_find, t_env_list **list)
{
	t_env_list	*temp;

	temp = *list;
	if (!to_find || !list)
		return (NULL);
	while (temp)
	{
		if (ft_strcmp(to_find, temp->front) != 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_env_list	**delete_node(t_env_list **list)
{
	t_env_list	*temp;

	if (!list || !*list)
		return (NULL);
	temp = *list;
	*list = temp->next;
	if (*list)
		(*list)->prev = temp->prev;
	free (temp->env_val);
	free (temp->front);
	free (temp);
	return (list);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:40:49 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/26 23:03:04 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"
#include <string.h>
#include <uchar.h>

/// @brief env_list size
/// @param list 
/// @return Size of env
int	env_size(t_env_list **list)
{
	t_env_list	*temp;
	int			i;

	if(!list || !*list)
		return (0);
	i = 0;
	temp = *list;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

/// @brief Print env
/// @param env 
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
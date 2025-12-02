/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:40:49 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/02 16:29:07 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include <string.h>
#include <uchar.h>

/// @brief env_list size
/// @param list 
/// @return Size of env
int	env_size(t_env_list **list)
{
	t_env_list	*temp;
	int			i;

	if (!list || !*list)
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

/// @brief print env
/// @param env 
/// @param flag 
void	print_env(t_env_list *env)
{
	int		i;

	i = 0;
	if (!env)
		return ;
	while (env)
	{
		printf("%s=%s\n", env->front, env->env_val);
		env = env->next;
		i++;
	}
	printf("number of env: %d\n", i);
	return ;
}

char	*get_value(char *key, t_env_list **list)
{
	t_env_list	*temp;
	char		*res;


	if (!key || !list || !*list)
		return (NULL);
	temp = find_env_key(key, list);
	res = ft_strdup(temp->env_val);
	return (res);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:48:14 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/04 13:41:13 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

char	**ft_2d_append_back(char **ori, char *content)
{
	int		td_size;
	int		i;
	char	**temp;

	td_size = 0;
	i = 0;
	if (!ori)
	{
		temp = malloc(sizeof(char *));
		temp[0] = ft_strdup(content);
		return (temp);
	}
	while(ori[td_size])
		td_size++;
	temp = malloc(sizeof(char *) * (td_size + 2));
	if (!temp)
		return (ft_free_str_arr(ori), NULL);
	while(i < td_size)
	{
		temp[i] = ft_strdup(ori[i]);
		i++;
	}
	temp[i] = ft_strdup(content);
	temp[i + 1] = NULL;
	return ((ft_free_str_arr(ori)), temp);
}

char	**ft_2d_dup(char **src)
{
	char	**temp;
	int		size;
	int		i;

	if (!src || !*src)
		return (NULL);
	while(src[size])
		size++;
	temp = malloc(sizeof(char *) * size + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while(i < size)
	{
		temp[i] = ft_strdup(src[i]);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

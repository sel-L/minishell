/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:16:03 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/05 16:16:23 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizing.h"

void	create_token(t_token **token, char *str)
{
	int		start;
	int		end;
	int		i;
	char	*temp;

	i = 0;
	start = 0;
	end = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (!check_m_char(str[i]))
		{
			create_m_token(token, str[i]);
			start++;
		}
		else
			end++;
		i++;
	}
	temp = ft_substr(str, start, (end - start));
	add_token(token, temp);
}
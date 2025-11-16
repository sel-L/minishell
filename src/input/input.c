/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:10:09 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/16 14:20:09 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/input.h"

/// @brief just a function that readline from tty
/// @param  none
/// @return line that's readed
char	*ft_readline(void)
{
	char	*str;

	str = readline("input goes here$ ");
	add_history(str);
	if (*str == 32 || str == NULL || *str == '\0')
		return (NULL);
	return (str);	
}
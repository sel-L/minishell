/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/15 16:50:15 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

int	main(void)
{
	t_token	*tokens;
	char	*str;

	while (1)
	{
		str = readline("line here$ ");
		add_history(str);
		if (*str == '\0' || str == NULL || *str == 32)
			continue ;
		tokens = tokenizer(str);
		printf("%d\n", validator(tokens));
		free (tokens);
	}
	return (0);

}
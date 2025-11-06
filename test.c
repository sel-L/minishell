/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:43:06 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/06 20:48:20 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int ac, char **av)
{
	int	INQUOTE = 0;

	if (ac < 2)
		return (1);
	while (*av[1])
	{
		if (*av[1] == '\'' && !INQUOTE)
			INQUOTE = 1;
		else if(INQUOTE == 1 && *av[1] == '\'')
				INQUOTE = 0;
		if (*av[1] == 32 && INQUOTE == 0)
			printf("\n");
		if (*av[1])
			printf("%c", *av[1]);
		av[1]++;
		printf(" QUOTE FLAG IS: %d\n", INQUOTE);
	}
	printf("\n");
	return (0);
}

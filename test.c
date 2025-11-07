/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:43:06 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/07 13:27:39 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_lex
{
	char	*start;
	char	*end;
}	t_lex;

char* substr(const char *src, int start_index, int length) {
    if (src == NULL || start_index < 0 || length < 0) {
        return NULL; // Handle invalid inputs
    }

    int src_len = strlen(src);
    if (start_index >= src_len) {
        return strdup(""); // Return empty string if start_index is out of bounds
    }

    int actual_length = length;
    if (start_index + length > src_len) {
        actual_length = src_len - start_index; // Adjust length if it exceeds string end
    }

    char *dest = (char*) malloc(sizeof(char) * (actual_length + 1));
    if (dest == NULL) {
        return NULL; // Handle memory allocation failure
    }

    strncpy(dest, src + start_index, actual_length);
    dest[actual_length] = '\0'; // Null-terminate the substring

    return dest;
}

void	print_token(t_lex *lex)
{
	int		size;
	char	*temp;

	size = lex->end - lex->start;
	temp = substr(lex->start, 0, size);
	printf("temp is: %s\n" ,temp);
	free (temp);
}

int	main(int ac, char **av)
{
	int		INQUOTE = 0;
	t_lex	lex;

	lex.start = av[1];
	lex.end = lex.start;
	if (ac < 2)
		return (1);
	while (*lex.end)
	{
		if (*lex.end == '\'' && !INQUOTE)
			INQUOTE = 1;
		else if(INQUOTE == 1 && *lex.end == '\'')
				INQUOTE = 0;
		if (*lex.end == 32 && INQUOTE == 0)
		{
			print_token(&lex);
			lex.start = lex.end;
			while (*lex.start == 32)
				lex.start++;
		}
		lex.end++;
	}
	print_token(&lex);
	printf("\n");
	return (0);
}

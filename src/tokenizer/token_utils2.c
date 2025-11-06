/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:16:03 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/06 11:30:27 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizing.h"

// void	create_word_token(t_token **token, t_lexer *lex)
// {
// 	char	*temp;
// 	int		size;

// 	size = lex->start - lex->end;
// }

t_lexer *create_and_init_lex(char *str)
{
	t_lexer *lex;

	lex = malloc(sizeof(t_lexer));
	if (!lex || !str)
		return (NULL);
	lex->start = 0;
	lex->end = 0;
	lex->quote = NO_QUOTE;
	return (lex);
}
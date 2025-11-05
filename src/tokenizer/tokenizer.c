/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:41:12 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/05 17:06:56 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizing.h"
char	*find_token(t_lexer *lex, char *str);

// Take string and split it to diff token
t_token	**tokenizer(char *str)
{
	t_lexer *lex;
	char	*temp;

	lex = malloc(sizeof(t_lexer));
	if (!str)
		return (NULL);
	lex->start = str;
	temp = find_token(lex, str);
	printf("%s\n", temp);
	free (temp);
	return (NULL);
}

void	create_m_token(t_token **tok, char token)
{
	if (token == '|')
		return (add_token(tok, "|"));
	else if(token == '<')
		return (add_token(tok, "<"));
	else if(token == '<')
		return (add_token(tok, ">"));
	else if(token == '<')
		return (add_token(tok, "("));
	else if(token == '<')
		return (add_token(tok, ")"));
}

char	*find_token(t_lexer *lex, char *str)
{
	lex->quote = NO_QUOTE;
	while (lex->end)
	{
		
	}
}


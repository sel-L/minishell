/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wee <wee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:41:12 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/05 23:45:35 by wee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizing.h"
t_lexer *create_and_init_lex(char *str);

// Take string and split it to diff token
void tokenizer(char *str)
{
	t_lexer *lexer;

	lexer = create_and_init_lex(str);
	printf("*start is %c\n", *lexer->start);
	printf("start is %s\n", lexer->start);
	return ;
}

void create_m_token(t_token **tok, char token)
{
	if (token == '|')
		return (add_token(tok, "|"));
	else if (token == '<')
		return (add_token(tok, "<"));
	else if (token == '<')
		return (add_token(tok, ">"));
	else if (token == '<')
		return (add_token(tok, "("));
	else if (token == '<')
		return (add_token(tok, ")"));
	return ;
}

void	find_token(t_token **token, t_lexer *lex)
{
	while (*lex->start)
	{
		
	}
}

t_lexer *create_and_init_lex(char *str)
{
	t_lexer *lex;

	lex = malloc(sizeof(t_lexer));
	if (!lex || !str)
		return (NULL);
	lex->start = str;
	lex->end = lex->start;
	lex->quote = NO_QUOTE;
	return (lex);
}

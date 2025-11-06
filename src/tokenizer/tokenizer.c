/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:41:12 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/06 12:49:35 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizing.h"
t_lexer *create_and_init_lex(char *str);
void	create_w_token(t_token **token, t_lexer *lex);

// Take string and split it to diff token
void tokenizer(char *str)
{
	//t_lexer *lexer;

	lexer = create_and_init_lex(str);
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
	else if (token == '>')
		return (add_token(tok, "("));
	else if (token == '(')
		return (add_token(tok, ")"));
	return ;
}
// check for spaces
// if meta char or space or quote go in another if else condition
void	find_token(t_token **token, t_lexer *lex, char *str)
{
	lex->start = str;
	while (*str)
	{
		lex->end = str;
		if (ft_strchr(METACHARACTERS, *str) && *str != 32)
			create_m_token(token, *str);
		else if (*str == 32)
			create_w_token(token, lex);
		str++;
	}
}

void	create_w_token(t_token **token, t_lexer *lex)
{
	int		token_size;
	char	*tok;

	token_size = lex->end - lex->start;
	tok = ft_substr(lex->start, 0, token_size);
	if (!tok)
		return ;
	add_token(token, tok);
	lex->start = lex->end;
	free (tok);
}
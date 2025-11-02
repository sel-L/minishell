/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:41:12 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/02 15:35:18 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizing.h"

// Take string and split it to diff token
t_token	**tokenizer(char *str)
{
	int		i;
	t_token	*token;
	char	**cmd;
	
	if (!str)
		return (NULL);
	i = 0;
	
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

void	create_w_token(t_token **token, char *str)
{
	t_lexer	*lex;

	if (!str)
		return (NULL);
	lex->start = 0;
	lex->end = 0;
	while (str[lex->start])
	{
		if (check_m_char(str[lex->end]) && str[lex->end] != 32)
			lex->end++;
		if (str[lex->end] == 32)
			add_token(token, ft_substr(str, lex->start, (lex->end - lex->start)));
	}
}

void	create_token(t_token **token, char *str)
{
	int		start;
	int		end;
	int		i;
	char	*temp;

	if (!str)
		return (NULL);
	i = 0;
	start = 0;
	end = 0;
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

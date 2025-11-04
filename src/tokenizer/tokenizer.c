/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:41:12 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/04 17:32:05 by wshou-xi         ###   ########.fr       */
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
	(void)str;
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
	static int	start;
	static int	end;
	int			size;
	char		*temp;

	lex->quote = NO_QUOTE;
	while (str[end])
	{
		if (str[end] == '\'' || str[end] == '"')
			lex->quote = QUOTE;
		while (lex->quote)
		{
			if (str[end] == '\'' || str[end] == '"')
				lex->quote = NO_QUOTE;
			end++;
		}
		while (str[end] != 32 && lex->quote == NO_QUOTE
			&& !ft_strchr(METACHARACTERS, str[end]))
			end++;
		break ;
	}
	size = end - start;
	temp = ft_substr(str, start, size);
	start = end;
	return (temp);
}

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

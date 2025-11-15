/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_ep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:57:24 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/14 14:21:23 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"
static void	*create_and_add_token(t_token **tokens, char *token);
static int	identify_token_type(char *token);

/// @brief tokenizer, takes in a string and split it to diff token, each token node consist one token and the token type
/// @param str 
/// @return token list to build ast
t_token	*tokenizer(char *str)
{
	char	**splitted_tokens;
	t_token	*tokens;
	t_token *temp;
	int		i;

	if (!str)
		return (NULL);
	tokens = NULL;
	splitted_tokens = ft_split(str, ' ');
	i = 0;
	while(splitted_tokens[i])
	{
		tokens = create_and_add_token(&tokens, splitted_tokens[i]);
		i++;
	}
	temp = tokens;
	while (temp->next)
	{
		printf("token = \t%s\n", temp->value);
		printf("token type = \t%d\n", temp->type);
		printf("\n");
		temp = temp->next;
	}
	return (tokens);
}

/// @brief create a token node and append to back of tokens
/// @param tokens 
/// @param token 
/// @return void 
static void	*create_and_add_token(t_token **tokens, char *token)
{
	t_token	*tok;
	t_token	*last;
	int		token_type;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	token_type = identify_token_type(token);
	tok->value = token;
	tok->type = token_type;
	tok->next = NULL;
	if (*tokens == NULL)
		*tokens = tok;
	else
	{
		last = *tokens;
		while(last->next != NULL)
			last = last->next;
		last->next = tok;
	}
	printf("token = \t%s\n", tok->value);
	printf("token type = \t%d\n", tok->type);
	printf("\n");
	return (tok);
}

/// @brief identify each token and return each token type
/// @param token 
/// @return token type
static int	identify_token_type(char *token)
{
	printf ("token in identifier is %s\n", token);
	if (ft_strnstr(token, "<<", 2))
		return (HERE_DOC);
	else if (ft_strnstr(token, ">>", 2))
		return (APPEND);
	else if (ft_strchr(token, '<'))
		return (REDIR_IN);
	else if (ft_strchr(token, '>'))
		return (REDIR_OUT);
	else if (ft_strchr(token, '|'))
		return (PIPE);
	return (WORD);
}

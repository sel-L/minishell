/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:34:40 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/02 13:37:16 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizing.h"

// add content to each node

t_token	*new_node(char *str)
{
	t_token	*tok;
	int		size;

	tok = malloc(sizeof(t_token));
	if (tok == NULL)
		return (NULL);
	size = ft_strlen(str);
	tok->token = str;
	tok->size = size;
	tok->next = NULL;
	return (tok);
}

t_token	*toklast(t_token *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	tokadd_back(t_token **lst, t_token *new)
{
	t_token	*l;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	l = toklast(*lst);
	l->next = new;
}

int	check_m_char(char str)
{
	int	j;

	j = 0;
	while (j < 9)
	{
		if (str == METACHARACTERS[j])
			return (1);
		j++;
	}
	return (0);
}

void	add_token(t_token **token, char *str)
{
	t_token	*temp;

	temp = new_node(str);
	tokadd_back(token, temp);
}

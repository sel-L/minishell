/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:29:30 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/04 12:29:08 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

static int	is_redir(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

t_node	*token_to_node(char **argv)
{
	t_node 	*node;
	char	**temp;
	int		i;

	while (temp)
	{
		if(is_redir(argv[i][0]))
	}
}

t_node	*create_node(char **argv)
{
		t_node 	*node;

	node = malloc(sizeof(t_node));
	node->cmd = ft_strdup(argv[0]);
	node->argv = ft_2d_dup(argv);
	node->next = NULL;
}

void	add_node_back(t_node *src, t_node **node)
{
	t_node	*temp;

	if (!node)
		return ((*node = src));
	temp = *node;
	while(temp)
		temp = temp->next;
	temp->next = src;
	if (!src->next)
		src->next = NULL;
	return ;
}


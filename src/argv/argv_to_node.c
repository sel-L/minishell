/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:29:30 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/04 20:41:58 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

t_node	*create_node(char **argv);
void	add_node_back(t_node *src, t_node **node);

t_node	*token_to_node(t_token *token)
{
	t_node 			*node;
	t_node			*list;
	static t_token	*t_temp;
	char	**temp;

	t_temp = token;
	while(t_temp)
	{
		if (t_temp->type == WORD)
			temp = ft_2d_append_back(temp, t_temp->value);
		else
		{
			if (!temp)
				temp = ft_2d_append_back(temp, t_temp->value);
			node = create_node(temp);
			add_node_back(node, &list);
			free_node(node);
			ft_free_str_arr(temp);
			break ;
		}
	}
}

void	free_node(t_node *node)
{
	free(node->argv);
	free(node->cmd);
	free(node);
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
	{
		*node = src;
		return ;
	}
	temp = *node;
	while(temp)
		temp = temp->next;
	temp->next = src;
	if (!src->next)
		src->next = NULL;
	return ;
}


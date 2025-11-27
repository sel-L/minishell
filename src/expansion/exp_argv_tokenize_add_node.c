/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_argv_tokenize_add_node.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:52:44 by joloo             #+#    #+#             */
/*   Updated: 2025/11/27 15:16:48 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_argv_internal.h"

int	add_node(t_exp_argv_data *data, char *str, int len, int type)
{
	t_token	*node;

	node = ft_calloc(1, sizeof(t_token));
	if (node == NULL)
		return (FAILURE);
	if (str != NULL)
	{
		node->value = ft_substr(str, 0, len);
		if (node->value == NULL)
		{
			free(node);
			node = NULL;
			return (FAILURE);
		}
	}
	node->type = type;
	assign_list_ptr(&data->head, &data->tail, node);
	return (SUCCESS);
}

void	assign_list_ptr(t_token **head, t_token **tail, t_token *node)
{
	if ((*head) == NULL)
	{
		*head = node;
		*tail = node;
	}
	else
	{
		(*tail)->next = node;
		*tail = node;
	}
}

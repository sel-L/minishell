/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_print_tokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:42:24 by joloo             #+#    #+#             */
/*   Updated: 2025/11/14 15:23:37 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_internal.h"

void	tokenize_print_tokens(t_token *head, char **lookup)
{
	// (void) head;
	// (void) lookup;
	t_token	*curr;

	curr = head;
	while (curr != NULL)
	{
		printf("type: %s, value: %s\n", lookup[curr->type], curr->value);
		curr = curr->next;
	}
}

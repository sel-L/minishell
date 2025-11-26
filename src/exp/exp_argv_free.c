/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_argv_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:04:33 by joloo             #+#    #+#             */
/*   Updated: 2025/11/26 17:06:11 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_argv_internal.h"

void	expansion_argv_free(t_exp_argv_data *data)
{

}

void	free_tokens(t_token **lst)
{
	t_token	*temp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free((*lst)->value);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

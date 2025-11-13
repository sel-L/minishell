/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:37:52 by joloo             #+#    #+#             */
/*   Updated: 2025/11/13 12:54:33 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_internal.h"

void	tokenize_free(t_tok *data)
{
	ft_free_str_arr(data->token_lookup);
	data->token_lookup = NULL;
}

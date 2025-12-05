/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_argv_tokenize_detect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:24:30 by joloo             #+#    #+#             */
/*   Updated: 2025/11/27 15:59:36 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_argv_internal.h"

void	detect_quotes(char c, int *in_squote, int *in_dquote)
{
	if (c == '\'' && *in_dquote == 0)
	{
		if (*in_squote == 0)
			*in_squote = 1;
		else
			*in_squote = 0;
	}
	if (c == '\"' && *in_squote == 0)
	{
		if (*in_dquote == 0)
			*in_dquote = 1;
		else
			*in_dquote = 0;
	}
}

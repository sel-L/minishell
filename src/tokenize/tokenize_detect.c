/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_detect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:59:55 by joloo             #+#    #+#             */
/*   Updated: 2025/11/14 14:52:49 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_internal.h"
int	detect_quotes(char c)
{
	static int	in_squote;
	static int	in_dquote;

	if (c == '\'' && in_dquote == 0)
	{
		if (in_squote == 0)
			in_squote = 1;
		else
			in_squote = 0;
	}
	if (c == '\"' && in_squote == 0)
	{
		if (in_dquote == 0)
			in_dquote = 1;
		else
			in_dquote = 0;
	}
	if (in_squote == 1 || in_dquote == 1)
		return (TRUE);
	return (FALSE);
}

int	detect_type(t_tok *data, int i)
{
	int	type;

	type = 0;
	while (data->token_lookup[type] != NULL)
	{
		if (ft_strncmp(data->input + i, data->token_lookup[type],
				ft_strlen(data->token_lookup[type])) == 0)
			return (type);
		type++;
	}
	return (type);
}

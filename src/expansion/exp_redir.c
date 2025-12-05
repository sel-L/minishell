/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:32:50 by joloo             #+#    #+#             */
/*   Updated: 2025/12/05 13:35:34 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

// expand word for redirs
// performs expansion, word splitting and quote removal
char	**exp_word(char *str, t_env_list **env)
{
	char	**temp;
	char	**res;

	temp = ft_calloc(sizeof(char *) * 2));
	temp[0] = str;
	res = expand_argv(temp, env);
	free(temp);
	return (res);
}

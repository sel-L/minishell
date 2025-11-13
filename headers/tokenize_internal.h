/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:39:00 by joloo             #+#    #+#             */
/*   Updated: 2025/11/13 13:04:19 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_INTERNAL_H
# define TOKENIZE_INTERNAL_H

# include "tokenize.h"
# include "libft.h"

# ifndef SUCCESS
#  define SUCCESS 1
# endif

# ifndef FAILURE
#  define FAILURE 0
# endif

typedef struct s_tok
{
	char	*input;
	t_token	*head;
	t_token	*tail;
	char	**token_lookup;
}	t_tok

#endif
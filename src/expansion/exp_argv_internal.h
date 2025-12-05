/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_argv_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:23:19 by joloo             #+#    #+#             */
/*   Updated: 2025/12/05 13:35:45 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_ARGV_INTERNAL_H
# define EXPANSION_ARGV_INTERNAL_H

# include "libft.h"
# include "expansion.h"

# ifndef SUCCESS
#  define SUCCESS 1
# endif

# ifndef FAILURE
#  define FAILURE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef enum e_token_type
{
	VAR,
	DOUBLE_QUOTED_VAR,
	DELIMITER,
	WORD,
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

typedef struct s_exp_argv_data
{
	char		**argv;
	t_env_list	**env;
	char		**res;
	int			type;
	t_token		*head;
	t_token		*tail;
	int			in_squote;
	int			in_dquote;
}	t_exp_argv_data;

#endif
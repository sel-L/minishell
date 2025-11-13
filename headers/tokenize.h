/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:39:05 by joloo             #+#    #+#             */
/*   Updated: 2025/11/13 13:00:31 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

typedef enum e_token_type
{
	HERE_DOC,
	APPEND,
	REDIR_IN,
	REDIR_OUT,
	PIPE,
	WORD,
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

t_token	*tokenize(char *input);

#endif
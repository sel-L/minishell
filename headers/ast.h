/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:26:34 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/21 11:32:49 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

#include <linux/limits.h>
typedef struct s_ast
{
	char			*token;
	int				type;
	struct s_ast	*next;
	struct s_ast	*prev;
}	t_ast;

typedef enum e_node_type
{
	PIPE,
	SIMPLE_COM
}	t_node_type;

#endif
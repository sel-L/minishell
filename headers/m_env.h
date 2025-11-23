/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_env.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:28:05 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/23 21:45:09 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_ENV_H
#define M_ENV_H

typedef struct	s_env_list
{
	char				*front;
	char				*env_val;
	struct s_env_list	*next;
	struct s_env_list	*prev;
}	t_env_list;

t_env_list	**delete_node(t_env_list **list);
t_env_list	*find_env_front(char *to_find, t_env_list **list);

#endif
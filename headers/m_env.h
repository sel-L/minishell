/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_env.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:28:05 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/26 15:10:27 by wshou-xi         ###   ########.fr       */
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
int			change_value(char *src, t_env_list **list);
int			add_env_node(t_env_list *node ,t_env_list **list);
void		free_env(t_env_list *env_list);

#endif
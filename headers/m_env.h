/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_env.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:28:05 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/22 16:31:53 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_ENV_H
#define M_ENV_H

typedef struct	s_env_list
{
	char				*env_val;
	struct s_env_list	*next;
}	t_env_list;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:58:47 by joloo             #+#    #+#             */
/*   Updated: 2025/12/05 20:31:48 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_internal.h"

void	hd_free(t_hd *data)
{
	if (data->delimiter != NULL)
	{
		free(data->delimiter);
		data->delimiter = NULL;
	}
	if (data->buffer != NULL)
	{
		free(data->buffer);
		data->buffer = NULL;
	}
	if (data->written != TRUE && data->pipe[0] != -1)
	{
		close(data->pipe[0]);
		data->pipe[0] = -1;
	}
	if (data->pipe[1] != -1)
	{
		close(data->pipe[1]);
		data->pipe[1] = -1;
	}
}

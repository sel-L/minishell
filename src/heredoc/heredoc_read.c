/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 20:36:10 by joloo             #+#    #+#             */
/*   Updated: 2025/12/05 21:06:10 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_internal.h"

int	read_stdin(t_hd *data)
{
	// todo: alternative to free_gnl?
	char	*line;
	char	**lines;

	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		if (check_delimiter(line, data->delimiter) == TRUE)
			break ;
		lines = ft_realloc(&lines, 0, i, i + 1);
		if (lines == NULL)
			return (free(line), ft_free_str_arr(lines), FAILURE);
		lines[i] = line;
		line = get_next_line(fd);
		i++;
	}
	lines[i] = NULL;
	if (free_gnl(data, 0) == FAILURE)
		return (ft_free_str_arr(lines), FAILURE);
	data->buffer = ft_flatten(lines, NULL)
	if (data->buffer == NULL)
		return (ft_free_str_arr(lines), FAILURE);
	ft_free_str_arr(lines);
	return (SUCCESS);
}

int	check_delimiter(char *line, char *delimiter)
{
	int	len;

	len = ft_strlen(line);
	if (len == 0)
		return (FALSE);
	if (line[len - 1] != '\n')
		return (FALSE);
	if (ft_strlen(line) - 1 != ft_strlen(delimiter))
		return (FALSE);
	if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) != 0)
		return (FALSE);
	return (TRUE);
}

int	free_gnl(t_data *data, int fd)
{
	int	pipe[2];
	int	temp;

	temp = dup(fd);
	if (pipe(pipe) == -1)
		return (FAILURE);
	dup2(pipe[1], fd);
	get_next_line(fd);
	dup2(temp, fd);
	close(pipe[1]);
	close(pipe[0]);
	close(temp);
	return (SUCCESS);
}

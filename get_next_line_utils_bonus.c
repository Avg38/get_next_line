/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:06:32 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/21 14:03:03 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*str_init(char	*line)
{
	line = (char *)malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = 0;
	return (line);
}

char	*buffer_init(int fd, t_fd *buffer_memory)
{
	int	i;

	i = 0;
	fd++;
	while (i < MAX_FD && buffer_memory[i].fd != fd)
	{
		if (buffer_memory[i].fd == 0)
		{
			buffer_memory[i].fd = fd;
			return (buffer_memory[i].buffer);
		}
		i++;
	}
	if (buffer_memory[i].fd == fd)
		return (buffer_memory[i].buffer);
	return (NULL);
}

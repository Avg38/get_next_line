/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:52:59 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/12 14:21:22 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *str)
{
	size_t	i;
	size_t	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		write(1, &c, 1);
	}
}

char	*get_next_line(int fd)
{
	size_t		i;
	static char	buffer[BUFFER_SIZE];
	char		*line;

	i = 0;
	if (buffer)
		line = rm_buffer(buffer);
	while (buffer[i] != '\n')
	{
		if (read(fd, buffer, BUFFER_SIZE) == -1)
			return (NULL);
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				line = ft_strjoin(line, buffer);
				return (line);
			}
			i++;
		}
		ft_strjoin(line, buffer);
		i = 0;
	}
	return (NULL);
}


#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("fichier.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	ft_putstr(get_next_line(fd));
	close(fd);
	return (0);
}

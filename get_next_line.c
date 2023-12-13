/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:52:59 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/12 16:54:46 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)\n", 7);
		return ;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	check_backline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*extract_line(char *line, char *buffer, int bytes)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			line = gnl_ft_strjoin(line, buffer, i);
			return (line);
		}
		i++;
	}
	line = gnl_ft_strjoin(line, buffer, bytes);
	if (bytes < BUFFER_SIZE)
		return (line);
	return (line);
}

char	*get_next_line(int fd)
{
	static int	bytes;
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = rm_buffer(buffer, bytes);
	if (!line)
		line = malloc(sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1 || bytes == 0)
		{
			free(line);
			return (NULL);
		}
		line = extract_line(line, buffer, bytes);
		if (check_backline(buffer) == 1 || bytes < BUFFER_SIZE)
			return (line);
	}
	return (NULL);
}

int	main(void)
{
	int	fd;

	fd = open("fichier.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}

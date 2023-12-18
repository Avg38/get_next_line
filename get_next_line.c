/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:52:59 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/18 16:45:29 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *str)
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

int	extract_line(char **line, char *buffer, int bytes)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			*line = ft_strjoin_gnl(*line, buffer, i);
			return (1);
		}
		i++;
	}
	*line = ft_strjoin_gnl(*line, buffer, bytes);
	if (bytes < BUFFER_SIZE)
		return (1);
	return (0);
}

char	*update_line(char *line)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (line[i] != '\n')
	{
		dest[i] = line[i];
		i++;
	}
	dest[i] = line[i];
	i++;
	dest[i] = 0;
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	bytes;
	int			tmp_bytes;
	char		*line;

	line = rm_buffer(buffer, bytes);
	if (!line || BUFFER_SIZE < 1)
		return (NULL);
	if (check_newline(line) == 1)
		return (update_line(line));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (tmp_bytes == BUFFER_SIZE && bytes == 0)
			return (line);
		if (bytes == -1 || bytes == 0)
			return (free(line), NULL);
		if (extract_line(&line, buffer, bytes) == 1)
			return (line);
		tmp_bytes = bytes;
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;
	int	i = 0;

	fd = open("fichier.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
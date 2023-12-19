/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:52:59 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/19 16:41:09 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (0);
}

char	*extract_line(char *line, char *buffer)
{
	int		i;
	size_t	j;
	size_t	len_buffer;
	char	*dest;

	len_buffer = ft_strlen_gnl(buffer);
	dest = malloc((ft_strlen_gnl(line) + len_buffer + 1) * sizeof(char));
	if (!dest)
		return (free(line), NULL);
	i = -1;
	while (line[++i])
		dest[i] = line[i];
	free(line);
	j = 0;
	while (j < len_buffer && buffer[j - 1] != '\n')
		dest[i++] = buffer[j++];
	dest[i] = 0;
	return (dest);
}

int	update_gnl(char *new_buffer, char *buffer, char **line)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	new_buffer[i] = 0;
	*line = extract_line(*line, new_buffer);
	if (!*line)
		return (-1);
	return (1);
}

char	*run_read(int fd, char *line, char *buffer)
{
	ssize_t	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			break ;
		buffer[bytes] = 0;
		line = extract_line(line, buffer);
		if (!line)
			return (NULL);
		if ((check_newline(line) > 0 || bytes == 0) && line[0] != 0)
			return (line);
	}
	buffer[0] = 0;
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	line = str_init(line);
	if (!line)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 1
		|| update_gnl(buffer, &buffer[check_newline(buffer)], &line) < 0)
		return (free(line), NULL);
	if (check_newline(buffer) > 0)
		return (line);
	return (run_read(fd, line, buffer));
}

# include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int	i = 0;

	fd = open("fichier.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line = %s", line);
		free(line);
	}
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:52:59 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/14 18:07:22 by avialle-         ###   ########.fr       */
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
		if (str[i] == '\n')
			write(1, "\\\n", 2);
		else
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
	int		i;
	char	*dest;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[i] = 0;
	i = 0;
	while (line[i] != '\n')
	{
		dest[i] = line[i];
		i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	bytes;
	int			tmp_bytes;
	char		*line;

	line = rm_buffer(buffer, bytes);
	if (!line)
		return (NULL);
	if (check_backline(line) == 1)
		return (update_line(line));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (tmp_bytes == BUFFER_SIZE && bytes == 0)
		{

			return (line);
		}
		if (bytes == -1 || bytes == 0)
			return (free(line), NULL);
		if (extract_line(&line, buffer, bytes) == 1)
		{
			return (line);
		}
		tmp_bytes = bytes;
	}
	return (NULL);
}

int	main(void)
{
	int	fd;

	fd = open("fichier.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:06:32 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/18 16:45:47 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin_gnl(char *line, char *buffer, size_t len_buffer)
{
	size_t	i;
	size_t	j;
	size_t	len_line;
	char	*dest;

	len_line = ft_strlen_gnl(line);
	dest = malloc((len_line + len_buffer + 1) * sizeof(char));
	if (!dest)
		return (line);
	i = 0;
	while (i < len_line)
	{
		dest[i] = line[i];
		i++;
	}
	free(line);
	j = 0;
	while (j < len_buffer)
		dest[i++] = buffer[j++];
	dest[i] = buffer[j];
	i++;
	dest[i] = 0;
	return (dest);
}

char	*update_buffer(char *buffer, size_t i)
{
	size_t	j;

	j = 0;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		j++;
		i++;
	}
	while (j < BUFFER_SIZE)
		buffer[j++] = 0;
	return (buffer);
}

char	*rm_buffer(char *buffer, int bytes)
{
	size_t	i;
	size_t	len;
	char	*dest;

	i = 0;
	if (buffer[0] == 0 || bytes < BUFFER_SIZE)
		return (malloc(sizeof(char)));
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (i == BUFFER_SIZE)
		return (malloc(sizeof(char)));
	buffer = update_buffer(buffer, i + 1);
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	len = ft_strlen_gnl(buffer);
	while (i < len)
	{
		dest[i] = buffer[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

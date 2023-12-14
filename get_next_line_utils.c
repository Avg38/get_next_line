/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:06:32 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/14 18:04:57 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *dest, char *src, int n)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i] && i <= n)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = 0;
	return (dest);
}

char	*ft_strjoin_gnl(char *line, char *buffer, size_t len_buffer)
{
	size_t	i;
	size_t	j;
	size_t	len_total;
	size_t	len_line;
	char	*dest;

	len_line = ft_strlen(line);
	len_total = len_line + len_buffer;
	dest = malloc((len_total + 1) * sizeof(char));
	if (!dest)
		return (line);
	i = 0;
	dest[len_total] = 0;
	while (i < len_line)
	{
		dest[i] = line[i];
		i++;
	}
	j = 0;
	while (j < len_buffer)
	{
		dest[i] = buffer[j];
		i++;
		j++;
	}
	return (dest);
}

char	*update_buffer(char *buffer, int *i)
{
	int	j;

	j = 0;
	while (buffer[*i])
	{
		buffer[j] = buffer[*i];
		j++;
		(*i)++;
	}
	while (buffer[j])
	{
		buffer[j] = 0;
		j++;
	}
	*i = 0;
	while (buffer[*i])
		(*i)++;
	return (buffer);
}

char	*rm_buffer(char *buffer, int bytes)
{
	int		i;
	char	*dest;

	i = 0;
	if (buffer[0] == 0 || bytes < BUFFER_SIZE)
	{
		return (malloc(sizeof(char)));
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i++;
	buffer = update_buffer(buffer, &i);
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	return (ft_strdup(dest, buffer, i));
}

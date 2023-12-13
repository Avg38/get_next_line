/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:06:32 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/12 16:31:03 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = -1;
	while (++i < n)
		str[i] = 0;
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_strdup(char *dest, char *src, int n)
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
	dest[len + i] = '\0';
	return (dest);
}

char	*gnl_ft_strjoin(char *line, char *buffer, size_t len_buffer)
{
	size_t	i;
	size_t	j;
	size_t	len_line;
	size_t	len_total;
	char	*dest;

	if (!line)
		len_line = 0;
	else
		len_line = ft_strlen(line);
	len_total = len_line + len_buffer;
	dest = malloc((len_total + 1) * sizeof(char));
	if (!dest)
		return (malloc(1));
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

char	*rm_buffer(char *buffer, int bytes)
{
	size_t	len_dest;
	int		i;
	size_t	j;
	char	*dest;

	i = 0;
	if (buffer[0] == '\0' || bytes < BUFFER_SIZE)
		return (NULL);
	while (buffer[i] != '\n')
		i++;
	len_dest = ft_strlen(buffer) - i;
	dest = malloc((len_dest + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len_dest] = 0;
	j = 0;
	while (buffer[i])
	{
		dest[j] = buffer[i];
		i++;
		j++;
	}
	ft_bzero(buffer, BUFFER_SIZE + 1);
	return (dest);
}

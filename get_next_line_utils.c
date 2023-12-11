/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:06:32 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/09 17:06:32 by avialle-         ###   ########.fr       */
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

size_t  ft_strlen(char *str)
{
    int i;

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

int  ft_lenLine(int fd)
{
    int     i;
    int     len;
    char    buffer[1025];

    i = 0;
    len = 0;
    ft_bzero(buffer, 1024);
    while (i < 1)
    {
        if (read(fd, buffer, 1024) == -1)
            return (-1);
        printf("%s\n", buffer);
        while (buffer[i] && buffer[i] != '\n')
        {
            len++;
            i++;
        }
        if (buffer[i] == '\n')
            return (len);
        i = 0;
    }
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:52:59 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/09 16:52:59 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *str)
{
	int	i;
	int c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		write(1, &c, 1);
	}
}

char *get_next_line(int fd)
{
	int		i;
	int		j;
	int		len;
	char	buffer[1025];
	char	**line;

	i = 0;
	j = 0;
	ft_bzero(buffer, 1025);
	// len = ft_lenLine(fd);
	if (len == -1)
		return (NULL);
	ft_bzero(line, len);
	while (j < len)
	{
		if (read(fd, buffer, 1024) == -1)
			return (NULL);
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				len = i + 1;
				ft_strncat(line, buffer, i);
				return (line);
			}
			i++;
		}
		len += i;
		ft_strdup(line[j], buffer, i);
		j++;
	}
	return (NULL);
}


#include <fcntl.h>

int main() {
    int fd = open("fichier.txt", O_RDONLY);
    if (fd == -1) {
        return (0);
    } else {
        ft_putstr(get_next_line(fd));
        close(fd);
    }
    return 0;
}
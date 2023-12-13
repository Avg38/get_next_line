/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:50:23 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/12 16:42:33 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char *str);
char	*gnl_ft_strjoin(char *line, char *buffer, size_t len_buffer);
char	*rm_buffer(char *buffer, int bytes);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-movcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:57:10 by m-movcha          #+#    #+#             */
/*   Updated: 2020/03/10 22:55:26 by m-movcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *end;

int get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	char *p;
	char flag;
	size_t nbytes;
	ssize_t bytes_read;
	
	flag = 1;
	if (end)
		*line = ft_strdup(end);
	else
		*line = ft_strnew(0);
	nbytes = sizeof(buf);
	while (flag && (bytes_read = read(fd, buf, nbytes)))
	{
		buf[bytes_read] = '\0';
		if (p = ft_strchr(buf, '\n'))
		{
			*p++ = '\0';
			end = ft_strdup(p);
			flag = 0;
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

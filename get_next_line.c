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

static t_fd	*ft_create_fd(const *str, const fd)
{
	t_fd *tmp;

	if (!str || !fd)
		return (NULL);
	if (!(tmp = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	tmp->fd = fd;
	tmp->str = str;
	tmp->next = NULL;
	return (tmp);
}

void		ft_fd_list_push(t_fd **list, t_fd *new)
{
	t_fd *tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*list = new;
}

ft_fd		*ft_fd_list_find(t_fd **list, const fd)
{
	t_fd *tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (0);
}

static int ft_get_line(t_fd *tmp, char **line)
{
	char buf[BUFF_SIZE + 1];
        char *p;
        char flag;
        size_t nbytes;
        ssize_t bytes_read;

        flag = 1;
        if (tmp->str)
                *line = ft_strdup(tm--str);
        else
                *line = ft_strnew(0);
        nbytes = sizeof(buf);
        while (flag && (bytes_read = read(tmp->fd, buf, nbytes)))
        {
                buf[bytes_read] = '\0';
                if (p = ft_strchr(buf, '\n'))
                {
                        *p++ = '\0';
                        tmp->str = ft_strdup(p);
                        flag = 0;
                }
                *line = ft_strjoin(*line, buf);
        }
        if (bytes_read)
                return (1);
        return (0);
}

int get_next_line(const int fd, char **line)
{
	static t_fd	*list;
	t_fd		*tmp;

	if (!fd || !line)
		return (-1);
	if (!(list))
		list = ft_fd_list_push(list, NULL, fd);
	tmp = list;
	
}

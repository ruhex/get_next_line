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

int get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE];
	size_t nbytes;
	ssize_t bytes_read;
	
	nbytes = sizeof(buf);
	bytes_read = read(fd, buf, nbytes);
}

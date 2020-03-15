/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-movcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:15:33 by m-movcha          #+#    #+#             */
/*   Updated: 2020/03/10 20:09:38 by m-movcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#define	GET_NEXT_LINE_H

#define BUFF_SIZE 32
#include <unistd.h>
#include <sys/types.h>
#include "libft/libft.h"

int get_next_line(const int fd, char **line);

#endif

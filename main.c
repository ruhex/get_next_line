/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-movcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:26:19 by m-movcha          #+#    #+#             */
/*   Updated: 2020/03/10 22:30:18 by m-movcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 32
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main (int a, char **c)
{

	//int open(const char *pathname, int flags);
	//int open(const char *pathname, int flags, mode_t mode);

	/* The open() system call opens the file specified by pathname.  If the
	specified file does not exist, it may optionally (if O_CREAT is
   	specified in flags) be created by open().

    	The return value of open() is a file descriptor, a small, nonnegative
    	integer that is used in subsequent system calls (read(2), write(2),
    	lseek(2), fcntl(2), etc.) to refer to the open file.  The file
    	descriptor returned by a successful call will be the lowest-numbered
    	file descriptor not currently open for the process.

    	By default, the new file descriptor is set to remain open across an
    	execve(2) (i.e., the FD_CLOEXEC file descriptor flag described in
    	fcntl(2) is initially disabled); the O_CLOEXEC flag, described below,
    	can be used to change this default.  The file offset is set to the
    	beginning of the file (see lseek(2)).

    	A call to open() creates a new open file description, an entry in the
    	system-wide table of open files.  The open file description records
    	the file offset and the file status flags (see below).  A file
    	descriptor is a reference to an open file description; this reference
    	is unaffected if pathname is subsequently removed or modified to
    	refer to a different file.  For further details on open file
    	descriptions, see NOTES.
    
    	??????????????????????????????????????????????????????????????????????

    	The argument flags must include one of the following access modes:
    	O_RDONLY, O_WRONLY, or O_RDWR.  These request opening the file read-
    	only, write-only, or read/write, respectively.
    
    	???????????????????????????????????????????????????????????????????????

    	In addition, zero or more file creation flags and file status flags
    	can be bitwise-or'd in flags.  The file creation flags are O_CLOEXEC,
    	O_CREAT, O_DIRECTORY, O_EXCL, O_NOCTTY, O_NOFOLLOW, O_TMPFILE, and
    	O_TRUNC.  The file status flags are all of the remaining flags listed
    	below.  The distinction between these two groups of flags is that the
    	file creation flags affect the semantics of the open operation
    	itself, while the file status flags affect the semantics of
    	subsequent I/O operations.  The file status flags can be retrieved
   	 and (in some cases) modified; see fcntl(2) for details. 
	
	man 2 open */
	
	int fd;

	char *line;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error open file");
		return (-1);
	}

	while (get_next_line(fd, &line))
		printf("%s\n", line);

	close(fd);
	system("leaks a.out");	
	return (0);
}


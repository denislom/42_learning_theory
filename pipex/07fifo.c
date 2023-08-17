/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07fifo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:40:46 by dlom              #+#    #+#             */
/*   Updated: 2023/08/17 22:46:45 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
/*
SOURCES:
[1]
KERRISK, Michael. The Linux programming interface: a Linux and UNIX system
programming handbook. San Francisco: No Starch Press, c2010.
ISBN 978-1-59327-220-3.
[2]
https://www.youtube.com/watch?v=2hba3etpoJg&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=9
	Pipe is in a memory file. You can write and read from it.
	int	pipe(int __pipedes[2])
		- if succesful, two file descriptors are stored in PIPEDES,
		byters written on PIPEDES[1] can be read from PIPEDES[0].
		RETURNS: 0 if succesful, -1 if not
	fd[0] - read
	fd[1] - write

	PIPE? -> communication between processes :)
	whenever we write or read, we should check for the errors

	In this example we are going to sum the elements
	of the array up taking advantage of multiprocesses
	on the computer. Half of the string will be calculated
	by 1 process and other half by 2nd


*/

int	main(int argc, char *argv[])
{
	int	fd;
	int	x;

	if (mkfifo("myfifo1", 0777) == -1)
	{
		if (errno != EEXIST)
		{
		printf("Could not create fifo.\n");
		return (1);
		}
	}
	// fd = open("myfifo1", O_WRONLY);
	fd = open("myfifo1", O_RDWR);
	x = 97;
	if (write(fd, &x, sizeof(x)) == -1)
		return (2);
	close(fd);
	return (0);
}

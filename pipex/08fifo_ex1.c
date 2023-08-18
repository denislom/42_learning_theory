/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08fifo_ex1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:20:18 by dlom              #+#    #+#             */
/*   Updated: 2023/08/18 17:48:05 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
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

	HOW PARENT AND CHILD COMMUNICATE BETWEEN EACH OTHER
*/

int	main(int argc, char *argv[])
{
	int	arr[5];
	int	i;
	int	fd;

	srand(time(NULL));
	i = 0;
	while (i < 5)
	{
		arr[i] = rand() % 100;
		i++;
	}
	if (fd = open("sum", O_WRONLY) == -1)
		return (1);
	while (i < 5)
	{
		if (write(fd, &arr[1], sizeof(int)) == -1)
			return (2);
		printf("Wrote %d\n", arr[i]);
		i++;
	}
	close(fd);
	return (0);
}

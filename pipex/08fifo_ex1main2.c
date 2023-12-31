/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08fifo_ex1main2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:20:18 by dlom              #+#    #+#             */
/*   Updated: 2023/08/19 17:35:38 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
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


*/

int	main(int argc, char *argv[])
{
	int	arr[5];
	int	fd;
	int	i;
	int	sum;

	fd = open("sum", O_RDONLY);
	if (fd == -1)
	{
		printf("error");
		return (1);
	}
	i = 0;
	// while (i < 5)
	// {
	// 	if (read(fd, &arr[i], sizeof(int)) == -1)
	// 	{
	// 		printf("error 2");
	// 		return (2);
	// 	}
	// 	printf("Received %d\n", arr[i]);
	// 	i++;
	// }
	if (read(fd, arr, sizeof(int) * 5) == -1)
		return (2);
	close(fd);
	sum = 0;
	i = 0;
	while (i < 5)
	{
		sum = sum + arr[i];
		i++;
	}
	printf("Result is %d\n", sum);
}

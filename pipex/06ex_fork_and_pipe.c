/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06ex_fork_and_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:24:58 by dlom              #+#    #+#             */
/*   Updated: 2023/08/17 02:22:51 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
/*
SOURCES:
[1]
KERRISK, Michael. The Linux programming interface: a Linux and UNIX system
programming handbook. San Francisco: No Starch Press, c2010.
ISBN 978-1-59327-220-3.
[2]
https://www.youtube.com/watch?v=6u_iPGVkfZ4&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=7
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
	int	arr[] = {1, 2, 3, 4, 1, 2};
	int	fd[2];
	int	id;
	int	start;
	int	end;
	int	arrSize;
	int	sum;
	int	i;
	int	SumFromChild;
	int	totalSum;

	sum = 0;
	arrSize = sizeof(arr) / sizeof(int);
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		start = 0;
		end = start + arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}
	i = start;
	while (i < end)
	{
		sum = sum + arr[i];
		i++;
	}
	printf("Calculated sum: %d\n", sum);
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0], &SumFromChild, sizeof(SumFromChild));
		close(fd[0]);
		totalSum = sum + SumFromChild;
		printf("Total sum is %d\n", totalSum);
		wait(NULL);
	}
	return (0);
}

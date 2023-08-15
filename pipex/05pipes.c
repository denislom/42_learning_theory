/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05pipes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:24:18 by dlom              #+#    #+#             */
/*   Updated: 2023/08/15 22:32:46 by dlom             ###   ########.fr       */
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
https://www.youtube.com/watch?v=Mqb2dVRe0uo&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=6
	Pipe is in a memory file. You can write and read from it.
	int	pipe(int __pipedes[2])
		- if succesful, two file descriptors are stored in PIPEDES,
		byters written on PIPEDES[1] can be read from PIPEDES[0].
		RETURNS: 0 if succesful, -1 if not
*/

int	main(int argc, char *argv[])
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		printf("An error ocurred with opening the pipe\n");
		return (1);
	}
	return (0);
}

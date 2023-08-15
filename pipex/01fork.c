/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:14:27 by dlom              #+#    #+#             */
/*   Updated: 2023/08/02 01:05:45 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
/*
SOURCES:
[1]
KERRISK, Michael. The Linux programming interface: a Linux and UNIX system
programming handbook. San Francisco: No Starch Press, c2010.
ISBN 978-1-59327-220-3.
[2]
https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=1
fork():
	pid_t	fork(void);
		DESCRIPTION: 	creates  a  new process by duplicating the calling process
			The child process and the parent process run in separate memory spaces.
			At  the  time  of fork()  both  memory spaces have the same content.
		RETURN: -1 on errors, 0 in child process,
			in parent returns the id of child process
*/
int	main(int argc, char *argv[])
{
	int	id;

	id = fork();
	if (id != 0)
		id = fork();
	if (id == 0)
	{
		printf("Hello world from id %d, this is child process\n", id);
	}
	else
	{
		printf("Hello world from id %d, this is parent process\n", id);
	}
	return (0);
}

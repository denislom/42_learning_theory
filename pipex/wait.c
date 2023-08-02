/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:11:04 by dlom              #+#    #+#             */
/*   Updated: 2023/08/02 23:45:15 by dlom             ###   ########.fr       */
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
https://www.youtube.com/watch?v=tcYo6hipaSA&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=2
wait():
	#include <sys/wait.h>
	pid_t	wait(int *status);
		DESCRIPTION:	waits for one of the children process to terminate
		RETURN: process ID of terminated child, -1 on error
			returns the termination status of the child process in the 
				buffer pointed to by status.
*/

int	main(int argc, char *argv[])
{
	int	id;
	int	n;
	int	i;

	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		wait();
	i = n;
	while (i < n + 5)
	{
		printf("%d ", i);
		fflush(stdout);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:49:13 by dlom              #+#    #+#             */
/*   Updated: 2023/08/03 00:14:47 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*
SOURCES:
[1]
KERRISK, Michael. The Linux programming interface: a Linux and UNIX system
programming handbook. San Francisco: No Starch Press, c2010.
ISBN 978-1-59327-220-3.
[2]
https://www.youtube.com/watch?v=tcYo6hipaSA&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=4

       #include <sys/types.h>
       #include <unistd.h>

       pid_t getpid(void);
       pid_t getppid(void);
	getpid(): RETURNS the process ID of the calling process
	getppid(): RETURNS THE process ID of the parent of the calling procsess.
*/

int	main(int argc, char *argv[])
{
	int	id;
	int	res;

	id = fork();
	printf("Current id: %d, parent ID: %d\n", getpid(), getppid());
	res = wait(NULL);
	if (res == -1)
		printf("No children to wait for.\n");
	else
		printf("%d finished execution. \n", res);
	return (0);
}

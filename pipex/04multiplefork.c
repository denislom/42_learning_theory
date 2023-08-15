/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplefork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 00:37:19 by dlom              #+#    #+#             */
/*   Updated: 2023/08/15 21:22:25 by dlom             ###   ########.fr       */
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
https://www.youtube.com/watch?v=tcYo6hipaSA&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=5
Calling fork two times:
				____________
				|main pr.	|
				|id1 = x	|
				|id2 = z	|
				|___________|
			_____|______________
			|					|
	____________		____________
	|id1 = 0	|		|id1 = x	|
	|id2 = y	|		|id2 = 0	|
	|____X______|		|____Z______|
		|
	____________
	|id1 = 0	|
	|id2 = 0	|
	|____Y______|
	id of child is zero
	while (wait(NULL) != -1 || errno != ECHILD)
		- going to wait for all the processes
*/

int	main(int argc, char *arv[])
{
	int	id1;
	int	id2;

	id1 = fork();
	id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
			printf("We are process Y\n");
		else
			printf("We are process X\n");
	}
	else
	{
		if (id2 == 0)
			printf("We are process Z\n");
		else
			printf("We are the parent process!\n");
	}
	while (wait(NULL) != -1 || errno != ECHILD)
		printf("Waited for the child to finish.\n");	
	return (0);
}

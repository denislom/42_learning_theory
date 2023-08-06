/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplefork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 00:37:19 by dlom              #+#    #+#             */
/*   Updated: 2023/08/06 17:49:15 by dlom             ###   ########.fr       */
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
*/

int	main(int argc, char *arv[])
{
	int	id1;
	int	id2;

	id1 = fork();
	id2 = fork();
	return (0);
}

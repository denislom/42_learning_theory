/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:05:19 by dlom              #+#    #+#             */
/*   Updated: 2023/08/19 18:59:20 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/*
https://www.youtube.com/watch?v=8Q9CPWuRC6o&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=10
	two way communication between parent and child
*/
int	main(int argc, char *argv[])
{
	int	p1[2];
	int	pid;
	int	x;
	int	y;

	if (pipe(p1) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0)
	{
		// Child process
		if (read(p1[0], &x, sizeof(x)) == -1)
			return (3);
		printf("Child received %d\n", x);
		x = x * 4;
		if (write(p1[1], &x, sizeof(x)) == -1)
			return (4);
		printf("Child wrote %d\n", x);
	}
	else
	{
		// Parent process
		srand(time(NULL));
		y = rand() % 10;
		if (write(p1[1], &y, sizeof(y)) == -1)
			return (5);
		printf("Parent wrote %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1)
			return (6);
		printf("Result in parent is %d\n", y);
	}
	close(p1[0]);
	close(p1[1]);
	return (0);
}

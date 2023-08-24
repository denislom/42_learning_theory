/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18workingwithmultiplepipes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:31:13 by dlom              #+#    #+#             */
/*   Updated: 2023/08/24 15:52:27 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
https://www.youtube.com/watch?v=kCGaRdArSnA&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=25
*/

int	main(int argc, char *argv[])
{
	int	fd[3][2];
	int	i;
	int	pid1;
	int	pid2;

	i = 0;
	while (i < 3)
	{
		if (pipe(fd[i]) < 0)
			return (1);
		i++;
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);
		int	x;
		if (read(fd[0][0], &x, sizeof(int)) < 0)
			return (3);
		x = x + 5;
		if (write(fd[1][1], &x, sizeof(int)) < 0)
			return (4);
		close(fd[0][0]);
		close(fd[1][1]);
		return (0);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (5);
	if (pid2 == 0)
	{
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][1]);
		close(fd[2][0]);
		int	x;
		if (read(fd[1][0], &x, sizeof(int)) < 0)
			return (6);
		x = x + 5;
		if (write(fd[2][1], &x, sizeof(int)) < 0)
			return (7);
		close(fd[1][0]);
		close(fd[2][1]);
		return (0);
	}
	close(fd[0][0]);
	close(fd[1][0]);
	close(fd[1][1]);
	close(fd[2][1]);
	int	x;
	x = 0;
	if (write(fd[0][1], &x, sizeof(int)) < 0)
		return (8);
	if (read(fd[2][0], &x, sizeof(int)) < 0)
		return (9);
	printf("Result is %d\n", x);
	close(fd[0][1]);
	close(fd[2][0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
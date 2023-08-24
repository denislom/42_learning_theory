/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19forkmultipletimespart2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:57:45 by dlom              #+#    #+#             */
/*   Updated: 2023/08/24 16:31:03 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROCESS_NUM 3
/*
https://www.youtube.com/watch?v=VzCawLzITh0&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=26
*/

int	main(int argc, char *argv[])
{
	int	pids[PROCESS_NUM];
	int	pipes[PROCESS_NUM + 1][2];
	int	i;

	i = 0;
	while (i < PROCESS_NUM)
	{
		if (pipe(pipes[i]) == -1)
			return (1);
		i++;
	pids[i] = fork();
	if (pids[i] == -1)
		return (2);
	}
	if (pids[i] == 0)
	{
		int	j;
		j = 0;
		while (j < PROCESS_NUM)
		{
			if (i != j)
				close(pipes[j][0]);
			if (i + 1 != j)
				close(pipes[j][1]);
			j++;
		}
		int	x;
		if (read(pipes[1][0], &x, sizeof(int)) == -1)
			return (3);
		printf("(%d) got %d\n", i, x);
		x++;
		if (write(pipes[i + 1][1], &x, sizeof(int)) == -1)
			return (4);
		printf("(%d) sent %d\n", i, x);
		close(pipes[i][0]);
		close(pipes[i + 1][1]);
		return (0);
	}
	//Main process
	int	y;

	y = 5;
	printf("Main process sent %d\n", y);
	if (write(pipes[0][1], &y, sizeof(int)) == -1)
		return (4);
	if (read(pipes[PROCESS_NUM][0], &y, sizeof(int)) == -1)
		return (5);
	printf("Final result is %d\n", y);
	i = 0;
	while (i < PROCESS_NUM)
	{
		wait(NULL);
		i++;
	}
	return (0);
}
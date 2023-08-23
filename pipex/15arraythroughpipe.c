/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15arraythroughpipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:57:46 by dlom              #+#    #+#             */
/*   Updated: 2023/08/23 18:40:44 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

/*
https://www.youtube.com/watch?v=rE1n-4z_n0Y&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=21
	2 processes
	1) Child process should generate random numbers and send them to parent
	2) Parent receives, sum them and print the result.
*/
int	main(int argc, char *argv[])
{
	int	pid;
	int	fd[2];
	if (pipe(fd) == -1)
		return (2);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		close(fd[0]);
		int	n;
		int	i;
		int	arr[10];
		srand(time(NULL));
		n = rand() % 10 + 1;
		i = 0;
		while (i < n)
		{
			arr[i] = rand() % 11;
			printf("Generated = %d\n", arr[i]);
			i++;
		}
		if (write(fd[1], &n, sizeof(int)) < 0)
			return (4);
		printf("Sent n = %d\n", n);
		if (write(fd[1], arr, sizeof(int) * n) < 0)
			return (3);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int	arr[10];
		int	n;
		int	i;
		int	sum;
		if (read(fd[0], &n, sizeof(int)) < 0)
			return (5);
		if (read(fd[0], arr, sizeof(int) * 10) < 0)
			return (6);
		close(fd[0]);
		i = 0;
		sum = 0;
		while (i < n)
		{
			sum = sum + arr[i];
			i++;
		}
		printf("Result is: %d\n", sum);
		wait(NULL);
	}
	return (0);
}
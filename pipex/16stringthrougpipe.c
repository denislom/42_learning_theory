/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16stringthrougpipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:19:42 by dlom              #+#    #+#             */
/*   Updated: 2023/08/24 10:55:06 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/*
https://www.youtube.com/watch?v=rE1n-4z_n0Y&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=22

*/
int	main(int argc, char *argv[])
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (2);
	if (pid == 0)
	{
		close(fd[0]);
		char str[200];
		int	n;

		printf("Input string: ");
		fgets(str, 200, stdin);
		n = strlen(str) + 1;
		str[strlen(str) - 1] = '\0';
		if (write(fd[1], &n, sizeof(int)) < 0)
			return (4);
		if (write(fd[1], str, sizeof(char) * (strlen(str) + 1)) < 0)
			return (3);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		char str[200];
		int	n;

		if (read(fd[0], &n, sizeof(int)) < 0)
			return (5);
		if (read(fd[0], str, sizeof(char) * n) < 0)
			return (6);
		printf("Received n: %d\nReceived string: %s\n",n, str);
		close(fd[0]);
		wait(NULL);
	}
	
	return (0);
}
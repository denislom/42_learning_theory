/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13redirectingstdout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:01:33 by dlom              #+#    #+#             */
/*   Updated: 2023/08/23 16:25:09 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

/*
https://www.youtube.com/watch?v=uh2FqejQRk8&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=14
*/

int	main(int argc, char *argv[])
{
	int	pid;
	int	err;
	int	wstatus;
	int	statusCode;
	int	file;
	int	file2;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("This should print on terminal.\n");
		file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
		printf("The duplicated fd to pingResults: %d\n", file);
		file2 = dup2(file, STDOUT_FILENO);
		printf("The duplicated fd: %d\n", file2);
		close(file);
		
		if (file == -1)
			return (3);
		err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err == -1)
		{
			printf("Could not find program to execute.");
			return (2);
		}
		printf("This should not print on terminal.\n");
	}
	else
	{
		// parent process
		printf("before wait\n");
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("succes\n");
			else
				printf("failure with status code %d\n", statusCode);
		}

		printf("Some post processing goes here.\n");
	}
	return (0);
}

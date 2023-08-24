/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17simulatingpipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:54:23 by dlom              #+#    #+#             */
/*   Updated: 2023/08/24 13:29:40 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
https://www.youtube.com/watch?v=6xbLgZpOBi8&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=23
ping -c 3 google.com | grep rtt
2 programs: ping and grep
pipe operator: |
	we are opening pipe that has 2 ends.
	ping -> stdout -> pipe -> stdin -> grep
*/

int	main(int argc, char *argv[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		// Child process 1: ping
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}
	pid2 = fork();
	if (pid2 < 0)
		return(3);
	if (pid2 == 0)
	{
		// Child process 2: grep
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}
	
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
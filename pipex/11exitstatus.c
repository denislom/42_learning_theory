/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11exitstatus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:22:03 by dlom              #+#    #+#             */
/*   Updated: 2023/08/22 14:40:55 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10executingcommands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:15:08 by dlom              #+#    #+#             */
/*   Updated: 2023/08/22 13:12:14 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

/*
https://www.youtube.com/watch?v=uh2FqejQRk8&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=12
*/

int	main(int argc, char *argv[])
{
	int	pid;
	int	err;
	int	wstatus;
	int	statusCode;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("This should print on terminal.\n");
		err = execlp("ping", "ping", "-c", "3", "google.con", NULL);
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

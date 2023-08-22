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
https://www.youtube.com/watch?v=uh2FqejQRk8&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=11
*/

int	main(int argc, char *argv[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("This should print on terminal.\n");
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
		printf("This should not print on terminal.\n");

	}
	else
	{
		// parent process
		printf("before wait\n");
		wait(NULL);
		printf("succes\n");
		printf("Some post processing goes here.\n");

	}
	return (0);
}

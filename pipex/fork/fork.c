/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:14:27 by dlom              #+#    #+#             */
/*   Updated: 2023/08/02 00:37:28 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	id;

	id = fork();
	if (id == 0)
	{
		printf("Hello world from id %d, this is child process\n", id);
	}
	else
	{
		printf("Hello world from id %d, this is parent process\n", id);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12executeotherprogram.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:26:55 by dlom              #+#    #+#             */
/*   Updated: 2023/08/23 14:00:44 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
/*
https://www.youtube.com/watch?v=uh2FqejQRk8&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=13
*/

int	main(int argc, char *argv[])
{
	int	err;

	execlp("ping2", "ping", "-c", "3" "google.com", NULL);
	err = errno;
	printf("Ping finished executing with err %d.\n", err);
	return (0);
}
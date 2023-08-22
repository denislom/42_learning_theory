/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12executeotherprogram.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:26:55 by dlom              #+#    #+#             */
/*   Updated: 2023/08/22 16:44:30 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
/*

*/

int	main(int argc, char *argv[])
{
	int	err;

	execlp("ping2", "ping", "google.com", NULL);
	err = errno;
	printf("Ping finished executing with err %d.\n", err);
	return (0);
}
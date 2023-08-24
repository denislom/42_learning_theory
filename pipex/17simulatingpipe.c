/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17simulatingpipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:54:23 by dlom              #+#    #+#             */
/*   Updated: 2023/08/24 13:02:41 by dlom             ###   ########.fr       */
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
	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdone <mdone@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:27:18 by mdone             #+#    #+#             */
/*   Updated: 2023/10/16 20:17:59 by mdone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_binary(int pid, char *str)
{
	int	i = 0;
	char *read = binary_to(str);
	while (read[i] != '\0')
	{
		if(read[i] == '1')
			kill(pid, SIGUSR1);
		if (read[i] == '0')
			kill(pid, SIGUSR2);
		usleep(37);		
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		get_binary(pid, argv[2]);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdone <mdone@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:33:08 by mdone             #+#    #+#             */
/*   Updated: 2023/11/05 15:57:28 by mdone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_binary(int pid, char *str)
{
	int		i;
	char	*read;

	i = 0;
	read = binary_to(str);
	while (read[i] != '\0')
	{
		if (read[i] == '1')
			kill(pid, SIGUSR1);
		if (read[i] == '0')
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
	free (read);
}

int	checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (checker(argv[2]) == 1)
		{
			get_binary(pid, argv[2]);
		}
		else
			write(1, "utf-8 ERROR", 11);
	}
	return (0);
}

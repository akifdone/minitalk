/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdone <mdone@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:26:51 by mdone             #+#    #+#             */
/*   Updated: 2023/10/16 20:20:30 by mdone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_signal(int s)
{
	static char		c = 0;
	static int		i = 128;

	if (s == SIGUSR1)
		c += i;
	i /= 2;
	if (i == 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 128;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, put_signal);
	signal(SIGUSR2, put_signal);
	while (1)
		pause();
	return (0);
}
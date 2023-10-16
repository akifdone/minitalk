/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdone <mdone@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:27:22 by mdone             #+#    #+#             */
/*   Updated: 2023/10/16 19:44:20 by mdone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (nb * -1);
	}
	if (nb < 10)
		ft_putchar_fd(nb + 48, fd);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char *binary_to(char *str) {
    
    size_t len = strlen(str);
    char *result = (char *)malloc((len * 8 + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int resultIndex = 0;
    int i = 0;
    while (i < len) {
        char bnry[9];
        binary_to_two((int)str[i], bnry, 7);
        binary_to_three(bnry, result, &resultIndex, len);
        i++;
    }

    return result;
}

void binary_to_two(int nbr, char bnry[], int j) {
    while (nbr) {
        if (nbr % 2 == 0) {
            bnry[j] = '0';
        } else {
            bnry[j] = '1';
        }
        nbr /= 2;
        j--;
    }
    while (j >= 0) {
        bnry[j] = '0';
        j--;
    }
    bnry[8] = '\0';
}

void binary_to_three(char bnry[], char result[], int *resultIndex, int len) {
    int k = 0;
    while (k < 8) {
        result[(*resultIndex)] = bnry[k];
        (*resultIndex)++;
        k++;
    }
}


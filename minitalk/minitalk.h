/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdone <mdone@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:25:20 by mdone             #+#    #+#             */
/*   Updated: 2023/10/16 19:45:19 by mdone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>


	void	ft_putnbr_fd(int n, int fd);
	void	ft_putchar_fd(char c, int fd);
	char 	*binary_to(char *str);
	void 	binary_to_two(int nbr, char bnry[], int j);
	void 	binary_to_three(char bnry[], char result[], int *resultIndex, int len);

#endif
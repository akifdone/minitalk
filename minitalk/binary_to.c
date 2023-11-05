/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdone <mdone@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:35:37 by mdone             #+#    #+#             */
/*   Updated: 2023/11/05 15:24:32 by mdone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*binary_to(char *str)
{
	size_t	len;
	char	*result;
	int		result_index;
	int		i;
	char	bnry[9];

	len = ft_strlen(str);
	result = (char *)malloc((len * 8 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	result_index = 0;
	while (i < len)
	{
		binary_to_two((int)str[i], bnry, 7);
		binary_to_three(bnry, result, &result_index, len);
		i++;
	}
	return (result);
}

void	binary_to_two(int nbr, char *bnry, int j)
{
	while (nbr)
	{
		if (nbr % 2 == 0)
			bnry[j] = '0';
		else
			bnry[j] = '1';
		nbr /= 2;
		j--;
	}
	while (j >= 0)
	{
		bnry[j] = '0';
		j--;
	}
	bnry[8] = '\0';
}

void	binary_to_three(char *bnry, char *result, int *result_index, int len)
{
	int	k;

	k = 0;
	while (k < 8)
	{
		result[(*result_index)] = bnry[k];
		(*result_index)++;
		k++;
	}
}

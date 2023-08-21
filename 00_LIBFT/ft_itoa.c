/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:58:29 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/21 17:16:50 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoa_len(int n)
{
	int			count;
	long int	copy;

	count = 0;
	copy = n;
	if (n < 0)
	{
		count++;
		copy = copy * (-1);
	}
	while (copy > 9)
	{
		copy = copy / 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	int			count;
	long int	copy;
	char		*number;

	count = ft_itoa_len(n);
	number = (char *) malloc ((count + 1) * sizeof(char));
	if (number == NULL)
		return (NULL);
	number[count--] = '\0';
	copy = n;
	if (n < 0)
	{
		number[0] = '-';
		copy = copy * (-1);
	}
	while (copy > 9)
	{
		number[count--] = (copy % 10) + '0';
		copy = copy / 10;
	}
	number[count] = copy + '0';
	return (number);
}

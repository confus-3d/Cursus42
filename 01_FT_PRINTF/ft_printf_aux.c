/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:06:04 by fde-los-          #+#    #+#             */
/*   Updated: 2023/09/30 11:59:06 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	if (s == NULL)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[len])
		len++;
	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}

int	ft_putnbr(int n, unsigned int number, int len, int templen)
{
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		number = n * -1;
		len++;
	}
	else
		number = n;
	if (number > 9)
	{
		templen = ft_putnbr(number / 10, 0, 0, 0);
		if (templen == -1)
			return (-1);
		len = len + templen;
		templen = ft_putnbr(number % 10, 0, 0, 0);
		if (templen == -1)
			return (-1);
		len = len + templen;
	}
	else if (number <= 9 && ++len > 0)
		if (ft_putchar(number + 48) == -1)
			return (-1);
	return (len);
}

int	ft_putunsnbr(unsigned int n)
{
	unsigned int	number;
	int				len;
	int				templen;

	len = 0;
	number = n;
	if (number > 9)
	{
		templen = ft_putunsnbr(number / 10);
		if (templen == -1)
			return (-1);
		len = len + templen;
		templen = ft_putunsnbr(number % 10);
		if (templen == -1)
			return (-1);
		len = len + templen;
	}
	else
	{
		if (ft_putchar((int)number + 48) == -1)
			return (-1);
		len++;
	}
	return (len);
}

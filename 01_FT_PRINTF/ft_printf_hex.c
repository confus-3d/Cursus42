/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:06:35 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/29 17:21:29 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr, int flag, int len, int templen)
{
	if (flag == 0)
	{
		templen = write (1, "0x", 2);
		if (templen == -1)
			return (-1);
		len = len + templen;
	}
	if (ptr > 15)
	{
		len = len + ft_putptr(ptr / 16, 1, 0, 0);
		len = len + ft_putptr(ptr % 16, 1, 0, 0);
	}
	else
	{
		if (ptr < 10)
			templen = ft_putchar(ptr + 48);
		else
			templen = ft_putchar(ptr - 10 + 'a');
		if (templen == -1)
			return (-1);
		len = len + templen;
	}
	return (len);
}

int	ft_puthex(unsigned int n, int len, int templen)
{
	unsigned int	number;

	number = n;
	if (number > 15)
	{
		templen = ft_puthex(number / 16, 0, 0);
		if (templen == -1)
			return (-1);
		len = len + templen;
		templen = ft_puthex(number % 16, 0, 0);
		if (templen == -1)
			return (-1);
		len = len + templen;
	}
	else
	{
		if (number < 10)
			templen = ft_putchar(number + 48);
		else
			templen = ft_putchar(number - 10 + 'a');
		if (templen == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_puthexup(unsigned int n, int len, int templen)
{
	unsigned int	number;

	number = n;
	if (number > 15)
	{
		templen = ft_puthexup(number / 16, 0, 0);
		if (templen == -1)
			return (-1);
		len = len + templen;
		templen = ft_puthexup(number % 16, 0, 0);
		if (templen == -1)
			return (-1);
		len = len + templen;
	}
	else
	{
		if (number < 10)
			templen = ft_putchar(number + 48);
		else
			templen = ft_putchar(number - 10 + 'A');
		if (templen == -1)
			return (-1);
		len++;
	}
	return (len);
}

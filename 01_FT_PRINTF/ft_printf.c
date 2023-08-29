/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:35:01 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/29 17:19:21 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ap(va_list ap, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (format == 'p')
		return (ft_putptr(va_arg(ap, unsigned long long), 0, 0, 0));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int), 0, 0, 0));
	if (format == 'u')
		return (ft_putunsnbr(va_arg(ap, unsigned int)));
	if (format == 'x')
		return (ft_puthex(va_arg(ap, int), 0, 0));
	if (format == 'X')
		return (ft_puthexup(va_arg(ap, int), 0, 0));
	if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;
	int		templen;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			templen = ft_printf_ap(ap, format[++i]);
		else
			templen = ft_putchar(format[i]);
		if (templen == -1)
			return (-1);
		len = len + templen;
		i++;
	}
	va_end(ap);
	return (len);
}
/*
#include <stdio.h>
int	main(void)
{
	ft_printf("FT:\001\002\007\v\010\f\rtry\n");
	printf("\n");
	printf("OG:\001\002\007\v\010\f\rtry\n");
	printf("\nEND\n");
}
*/

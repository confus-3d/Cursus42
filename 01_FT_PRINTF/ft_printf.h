/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:37:08 by fde-los-          #+#    #+#             */
/*   Updated: 2023/09/21 18:57:00 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printf_ap(va_list ap, const char format);

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n, unsigned int number, int len, int templen);
int	ft_putunsnbr(unsigned int n);

int	ft_putptr(unsigned long long ptr, int flag, int len, int templen);
int	ft_puthex(unsigned int n, int len, int templen, int upper);

#endif

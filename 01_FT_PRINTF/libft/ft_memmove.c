/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:54:33 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/17 19:32:32 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memmove(char *dst, const char *src, size_t len)
{
	unsigned int	count;

	count = 0;
	if (dst < src)
	{
		while (count < len)
		{
			dst[count] = src[count];
			count++;
		}
	}
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			dst[len] = src[len];
		}
	}
	return (dst);
}

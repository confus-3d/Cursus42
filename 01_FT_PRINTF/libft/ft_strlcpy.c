/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:27:43 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/17 19:35:49 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	count;
	unsigned int	srccount;

	count = 0;
	srccount = 0;
	while (src[srccount] != '\0')
		srccount++;
	while (src[count] != '\0' && dstsize > 1)
	{
		dst[count] = src[count];
		count++;
		dstsize--;
	}
	if (dstsize > 0)
		dst[count] = '\0';
	return (srccount);
}

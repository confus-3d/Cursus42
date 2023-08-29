/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:54:33 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/17 19:56:39 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	count;
	unsigned char	*copysrc;
	unsigned char	*copydst;

	count = 0;
	copysrc = (unsigned char *) src;
	copydst = (unsigned char *) dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (count < n)
	{
		copydst[count] = copysrc[count];
		count++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:57:54 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/17 19:42:42 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	counter;
	unsigned int	counter2;
	unsigned int	copy;

	counter = 0;
	counter2 = 0;
	copy = 0;
	if (size == 0)
	{
		while (src[counter] != '\0')
			counter++;
		return (counter + size);
	}
	while (dst[counter] != '\0' && counter < size)
		counter++;
	while (src[counter2] != '\0')
		counter2++;
	while (src[copy] != '\0' && (counter + copy) < (size - 1))
	{
		dst[counter + copy] = src[copy];
		copy++;
	}
	if (counter < size)
		dst[counter + copy] = '\0';
	return (counter + counter2);
}

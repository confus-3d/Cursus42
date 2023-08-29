/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:13:24 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/17 19:29:25 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copys;

	copys = (unsigned char *) s;
	while (n > 0)
	{
		if (*copys == (unsigned char) c)
			return (copys);
		copys++;
		n--;
	}
	return ((void *)0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:24:13 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/17 21:14:18 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	compare;
	unsigned char	*copys1;
	unsigned char	*copys2;

	copys1 = (unsigned char *) s1;
	copys2 = (unsigned char *) s2;
	compare = 0;
	if (n == 0)
		return (0);
	while (copys1[compare] == copys2[compare]
		&& compare < (n - 1))
		compare++;
	return (copys1[compare] - copys2[compare]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:57:52 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/17 19:36:39 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	compare;

	compare = 0;
	while ((unsigned char)s1[compare] == (unsigned char)s2[compare]
		&& s1[compare] != '\0' && compare < (n - 1))
		compare++;
	if (n == 0)
		return (0);
	return ((unsigned char)s1[compare] - (unsigned char)s2[compare]);
}

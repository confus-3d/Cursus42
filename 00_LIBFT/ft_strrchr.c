/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:14:51 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/17 19:37:54 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (c % 256 == 0)
		return ((char *)s + i);
	while ((s[i] != c % 256) && (i > 0))
		i--;
	if (s[i] == c % 256)
		return ((char *)s + i);
	else
		return ((void *)0);
}

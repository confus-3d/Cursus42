/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:37:52 by fde-los-          #+#    #+#             */
/*   Updated: 2023/09/30 11:59:49 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	counter;
	unsigned int	compare;

	counter = 0;
	compare = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[counter] && counter < len)
	{
		compare = 0;
		while (haystack[counter + compare] == needle[compare]
			&& counter + compare < len)
		{
			compare++;
			if (needle[compare] == '\0')
			{
				haystack = &haystack[counter];
				return ((char *)haystack);
			}
		}
		counter++;
	}
	return (0);
}

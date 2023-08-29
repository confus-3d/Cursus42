/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:27:29 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/17 20:35:47 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	counter;
	char			*dup;

	counter = 0;
	while (s1[counter] != 0)
		counter++;
	dup = (char *) malloc (counter + 1);
	if (dup == NULL)
		return (NULL);
	counter = 0;
	while (s1[counter] != 0)
	{
		dup[counter] = s1[counter];
		counter++;
	}
	dup[counter] = s1[counter];
	return (dup);
}

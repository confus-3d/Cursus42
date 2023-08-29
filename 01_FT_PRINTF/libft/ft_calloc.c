/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:00:53 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/17 20:25:41 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*space;
	size_t		counter;

	counter = 0;
	space = (char *) malloc (count * size);
	if (space == NULL)
		return (NULL);
	while (counter < (count * size))
	{
		space[counter] = 0;
		counter++;
	}
	return (space);
}

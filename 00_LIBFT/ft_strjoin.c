/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:59:58 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/17 23:19:20 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		counter1;
	int		counter2;
	int		size;

	counter1 = 0;
	counter2 = 0;
	size = -1;
	while (s1[counter1] != '\0')
		counter1++;
	while (s2[counter2] != '\0')
		counter2++;
	string = (char *) malloc (sizeof(char) * (counter1 + counter2 + 1));
	if (string == NULL)
		return (NULL);
	while (++size < counter1)
		string[size] = s1[size];
	size--;
	while (++size < counter1 + counter2)
		string[size] = s2[size - counter1];
	string[size] = '\0';
	return (string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:41:22 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/21 19:35:04 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_substr(char const *s)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	counter;

	counter = ft_strlen_substr(s);
	if (start >= counter)
	{
		substr = (char *) malloc (sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > counter - start)
		len = counter - start;
	substr = (char *) malloc (len + 1);
	if (substr == NULL)
		return (NULL);
	counter = 0;
	while (counter <= len)
		substr[counter++] = '\0';
	counter = 0;
	while (s[start + counter] != '\0' && counter++ < len)
		substr[counter - 1] = s[start + counter - 1];
	return (substr);
}

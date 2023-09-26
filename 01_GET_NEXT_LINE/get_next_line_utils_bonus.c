/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:31:40 by fde-los-          #+#    #+#             */
/*   Updated: 2023/09/26 15:34:11 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && *s != c % 256)
		s++;
	if (*s == c % 256)
		return ((char *)s);
	else
		return (NULL);
}

int	ft_strlen(const char *s)
{
	int	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		counter;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = (char *) malloc (size * sizeof(char));
	if (string == NULL)
		return (NULL);
	counter = 0;
	while (s1 && *s1)
	{
		string[counter++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		string[counter++] = *s2;
		s2++;
	}
	string[counter] = '\0';
	return (string);
}

void	ft_bzero(char *s, size_t n)
{
	unsigned int	count;

	count = 0;
	while (count < n)
	{
		s[count] = '\0';
		count++;
	}
}

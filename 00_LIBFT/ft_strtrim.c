/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:21:00 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/18 12:23:55 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_start(char *start, char *end, char const *set)
{
	int		counter;

	counter = 0;
	while (set[counter] != '\0' && end >= start)
	{
		if (*start == set[counter])
		{
			start++;
			counter = 0;
		}
		else
			counter++;
	}
	return (start);
}

char	*ft_end(char *start, char *end, char const *set)
{
	int		counter;

	counter = 0;
	while (set[counter] != '\0' && end >= start)
	{
		if (*end == set[counter])
		{
			end--;
			counter = 0;
		}
		else
			counter++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*answer;
	int		len;
	int		counter;

	len = 0;
	while (s1[len] != '\0')
		len++;
	start = (char *)s1;
	end = (char *)s1 + (len - 1);
	start = ft_start(start, end, set);
	end = ft_end(start, end, set);
	if (len > 0 && end >= start)
		len = end - start + 1;
	answer = (char *) malloc ((len + 1) * sizeof(char));
	if (answer == NULL)
		return (NULL);
	counter = -1;
	while (++counter < len)
		answer[counter] = start[counter];
	answer[counter] = '\0';
	return (answer);
}

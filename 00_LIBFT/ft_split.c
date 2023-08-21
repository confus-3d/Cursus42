/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:29:40 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/21 19:56:24 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split_countwords(char const *s, char c)
{
	int		len;
	int		counter;

	len = -1;
	counter = 0;
	while (s[++len] != '\0')
		if (s[len] != c && (s[len + 1] == c || s[len + 1] == '\0'))
			counter++;
	return (counter);
}

int	ft_strlen_stop(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

void	ft_strdup_stop(const char *s1, char *array, char c)
{
	unsigned int	counter;

	counter = 0;
	while (s1[counter] != '\0' && s1[counter] != c)
	{
		array[counter] = s1[counter];
		counter++;
	}
	array[counter] = '\0';
}

void	ft_free_all(char **array, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	int		counter;
	char	**array;

	array = (char **) malloc ((ft_split_countwords(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	len = -1;
	counter = -1;
	while (s[++len] != '\0')
	{
		if (s[len] != c && (len == 0 || s[len - 1] == c) && ++counter >= 0)
		{
			array[counter] = (char *) malloc ((ft_strlen_stop(&s[len], c)
						+ 1) * sizeof(char));
			if (array[counter] == NULL)
			{
				ft_free_all(array, counter);
				return (NULL);
			}
			ft_strdup_stop(&s[len], &array[counter][0], c);
		}
	}
	array[++counter] = NULL;
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:19:38 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/21 18:41:33 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*answer;

	len = 0;
	while (s[len] != '\0')
		len++;
	answer = (char *) malloc ((len + 1) * sizeof(char));
	if (answer == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		answer[len] = f(len, s[len]);
		len++;
	}
	answer[len] = '\0';
	return (answer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:51:27 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/21 19:06:05 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
}

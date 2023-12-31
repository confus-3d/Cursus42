/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:58:40 by fde-los-          #+#    #+#             */
/*   Updated: 2023/07/18 11:05:11 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	divide;

	divide = nb;
	if (nb < 2)
		return (0);
	else
	{
		while (--divide > 1)
			if ((nb % divide) == 0)
				return (0);
		return (1);
	}
}

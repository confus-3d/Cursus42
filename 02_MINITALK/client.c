/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:28:19 by fde-los-          #+#    #+#             */
/*   Updated: 2023/10/25 19:00:53 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	number = number * sign;
	return (number);
}

int	main(int argc, char **argv)
{
	int	serverpid;
	int	binary;

	binary = 7;
	serverpid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		while (argv[2][0] != '\0' && binary >= 0)
		{
			if (((int)argv[2][0] & (1 << binary)))
				kill(serverpid, SIGUSR1);
			else
				kill(serverpid, SIGUSR2);
			usleep(100);
			binary--;
			if (binary < 0)
			{
				binary = 7;
				argv[2]++;
			}
		}
	}
}

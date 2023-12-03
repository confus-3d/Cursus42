/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:28:19 by fde-los-          #+#    #+#             */
/*   Updated: 2023/10/27 11:30:44 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

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

//void    sig_handler(int signo, siginfo_t *info, void *empty)
void	sig_handler(int signo)
{
	if (signo == SIGUSR1)
	{
		write(1, "Message delivered.\n", 19);
	}
}

//act.sa_sigaction = &sig_handler;
void	set_signal_action(void)
{
	struct sigaction	act;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	act.sa_flags = 0;
	act.sa_mask = set;
	act.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &act, NULL);
}

void	send_message(int serverpid, char *message)
{
	int	binary;

	binary = 7;
	while (message[0] != '\0' && binary >= 0)
	{
		if (((int)message[0] & (1 << binary)))
		{
			if (kill(serverpid, SIGUSR1) == -1)
				exit(write(1, "Transmission error.\n", 20));
		}
		else
			if (kill(serverpid, SIGUSR2) == -1)
				exit(write(1, "Transmission error.\n", 20));
		usleep(150);
		binary--;
		if (binary < 0 && message++)
			binary = 7;
	}
	while (binary >= 0)
	{
		if (kill(serverpid, SIGUSR2) == -1)
			exit(write(1, "Confirmation error.\n", 20));
		usleep(150);
		binary--;
	}
}

int	main(int argc, char **argv)
{
	int	serverpid;

	if (argc == 3)
	{
		serverpid = ft_atoi(argv[1]);
		set_signal_action();
		send_message(serverpid, argv[2]);
		usleep(150);
	}
	if (argc != 3)
		write(1, "Format error: ./client PID MESSAGE\n", 35);
	return (0);
}

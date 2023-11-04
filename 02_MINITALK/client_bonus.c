/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:28:19 by fde-los-          #+#    #+#             */
/*   Updated: 2023/10/26 14:27:53 by fde-los-         ###   ########.fr       */
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
		write(1, "Mensaje enviado\n", 15);
	}
}

//act.sa_sigaction = &sig_handler;
void	set_signal_action(void)
{
	struct sigaction	act;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
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
			kill(serverpid, SIGUSR1);
		else
			kill(serverpid, SIGUSR2);
		usleep(150);
		binary--;
		if (binary < 0)
		{
			binary = 7;
			message++;
		}
	}
	while (binary >= 0)
	{
		kill(serverpid, SIGUSR2);
		usleep(150);
		binary--;
	}
}

int	main(int argc, char **argv)
{
	int	serverpid;

	serverpid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		set_signal_action();
		send_message(serverpid, argv[2]);
		sleep(1);
	}
	else
	{
		write(1, "Error.\nFormato: ./client PID MENSAJE\n", 37);
		exit(EXIT_FAILURE);
	}
	return (0);
}

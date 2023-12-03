/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:28:51 by fde-los-          #+#    #+#             */
/*   Updated: 2023/10/27 11:33:37 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	ft_putchar_putnbr_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n < 0)
	{
		ft_putchar_putnbr_fd('-', fd);
		number = n * -1;
	}
	else
		number = n;
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putnbr_fd(number % 10, fd);
	}
	else
		ft_putchar_putnbr_fd(number + 48, fd);
}

//void	sig_handler(int signo)
void	sig_handler(int signo, siginfo_t *info, void *empty)
{
	static unsigned char	c = '\0';
	static int				binary = 0;

	(void)empty;
	if (signo == SIGUSR2)
		c = c << 1;
	else if (signo == SIGUSR1)
		c = (c << 1) | 0b00000001;
	binary++;
	if (binary == 8)
	{
		if (c == '\0')
		{
			write(1, "   (", 4);
			ft_putnbr_fd(info->si_pid, 1);
			if (kill(info->si_pid, SIGUSR1) == -1)
				write(1, ") ✖\n", 6);
			else 
				write(1, ") ✔\n", 6);
		}
		else
			write(1, &c, 1);
		binary = 0;
		c = '\0';
	}
}

//act.sa_handler = &sig_handler;or act.sa_sigaction = &sig_handler;
void	set_signal_action(void)
{
	struct sigaction	act;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_flags = 0;
	act.sa_mask = set;
	act.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	main(void)
{
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	set_signal_action();
	while (1)
		sleep(1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:28:51 by fde-los-          #+#    #+#             */
/*   Updated: 2023/10/24 19:50:06 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	sig_handler(int signo)
{
	if (signo == SIGUSR2)
		write (1, "0", 1);
	if (signo == SIGUSR1)
		write (1, "1", 1);
}

void	set_signal_action(void)
{
	struct sigaction	act;
	sigset_t	set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_flags = 0;
	act.sa_mask = set;
	act.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	main (int argc, char**argv)
{
	char	letter;

	printf("Server PID: %d\n", getpid());
	set_signal_action();
	while (1)
		sleep(1);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:25:16 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/08/26 23:16:21 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_handler_bit(int signum, siginfo_t *info, void *context);

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID is: %d\n", getpid());
	sa.sa_sigaction = ft_handler_bit;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}

static void	ft_handler_bit(int signum, siginfo_t *info, void *context)
{
	static int		res = 0;
	static int		counter = 0;
	static pid_t	client_pid = -1;

	(void)context;
	if (client_pid == -1)
		client_pid = info->si_pid;
	if (signum == SIGUSR2)
		res |= (1 << (7 - counter));
	counter++;
	if (counter == 8)
	{
		ft_printf("%c", (unsigned char)res);
		if (res == 0)
		{
			ft_printf("\n");
			if (client_pid != -1)
				kill(client_pid, SIGUSR1);
			client_pid = -1;
		}
		res = 0;
		counter = 0;
	}
}

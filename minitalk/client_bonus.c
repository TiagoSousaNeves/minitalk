/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:12:49 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/08/26 23:27:20 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_confirm_received(int signum, siginfo_t *info, void *context);
static void	ft_send_msg(int server_pid, char *msg, int len_msg);

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*msg;
	int					len_msg;
	struct sigaction	sa;

	if (argc != 3)
		return (ft_printf("Error\nInvalid number of arguments.\n"
				"Correct format: ./client <PID> <MESSAGE>\n"));
	msg = argv[2];
	if (msg == NULL || !msg[0])
		return (ft_printf("Error\nEmpty message!\n"));
	len_msg = ft_strlen(msg);
	server_pid = ft_atoi_printf(argv[1]);
	if (server_pid <= 0)
		return (ft_printf("Error\nIncorrect SERVER PID!\n"));
	sa.sa_sigaction = ft_confirm_received;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	ft_send_msg(server_pid, msg, len_msg);
	return (0);
}

static void	ft_confirm_received(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	ft_printf("Message received! Thank you!\n");
}

static void	ft_send_msg(int server_pid, char *msg, int len_msg)
{
	int	i;
	int	bits;

	i = 0;
	while (i <= len_msg)
	{
		bits = 0;
		while (bits <= 7)
		{
			if (((msg[i] >> (7 - bits)) & 1) == 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			bits++;
			usleep(50);
		}
		i++;
	}
}

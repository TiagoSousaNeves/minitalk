/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 04:31:37 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/08/30 19:29:11 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_send_msg(int server_pid, char *msg, int len_msg);
static void	ft_confirm_received(int signum);

static volatile int	g_ack_received = 0;

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
		return (ft_printf("Empty message!\n"));
	len_msg = ft_strlen(msg);
	server_pid = ft_atoi_printf(argv[1]);
	if (server_pid <= 0)
		return (ft_printf("Error\nIncorrect SERVER PID!\n"));
	sa.sa_handler = ft_confirm_received;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_send_msg(server_pid, msg, len_msg);
	return (0);
}

static void	ft_confirm_received(int signum)
{
	if (signum == SIGUSR1)
		g_ack_received = 1;
	if (signum == SIGUSR2)
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
			g_ack_received = 0;
			if (((msg[i] >> (7 - bits)) & 1) == 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			while (!g_ack_received)
				;
			bits++;
		}
		i++;
	}
}

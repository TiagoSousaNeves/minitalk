/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:05:05 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/08/26 18:57:09 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_msg(int server_pid, char *msg, int len_msg);

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*msg;
	int		len_msg;

	if (argc != 3)
	{
		ft_printf("Error\nInvalid number of arguments.\n"
			"Correct format: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	msg = argv[2];
	if (msg == NULL || !msg[0])
	{
		ft_printf("Error\nEmpty message!\n");
		return (1);
	}
	len_msg = ft_strlen(msg);
	server_pid = ft_atoi_printf(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Error\nIncorrect SERVER PID!\n");
		return (1);
	}
	ft_send_msg(server_pid, msg, len_msg);
	return (0);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:25:16 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/08/26 18:58:17 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler_bit(int signum);

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID is: %d\n", getpid());
	sa.sa_handler = ft_handler_bit;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}

static void	ft_handler_bit(int signum)
{
	static int	res = 0;
	static int	counter = 0;

	if (signum == SIGUSR2)
		res |= (1 << (7 - counter));
	counter++;
	if (counter == 8)
	{
		ft_printf("%c", (unsigned char)res);
		if (res == 0)
			ft_printf("\n");
		res = 0;
		counter = 0;
	}
}

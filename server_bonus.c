/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:40:56 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/08/28 18:08:16 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler_bit(int signum, siginfo_t *info, void *context);
static void	ft_reset_message_state(char **msg, int *counter, int *res);
static void	ft_add_char_to_str(char c, char **str);
static void	ft_process_char(int *res, int *counter, char **msg, int pid);

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID is: %d\n", getpid());
	sa.sa_sigaction = ft_handler_bit;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

static void	ft_handler_bit(int signum, siginfo_t *info, void *context)
{
	static int		res = 0;
	static int		counter = 0;
	static char		*msg = NULL;
	static pid_t	prev_pid = 0;

	(void)context;
	if (info->si_pid != prev_pid)
	{
		ft_reset_message_state(&msg, &counter, &res);
		prev_pid = info->si_pid;
	}
	if (signum == SIGUSR2)
		res |= (1 << (7 - counter));
	counter++;
	if (counter == 8)
		ft_process_char(&res, &counter, &msg, info->si_pid);
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(EXIT_FAILURE);
}

static void	ft_process_char(int *res, int *counter, char **msg, int pid)
{
	ft_add_char_to_str(*res, msg);
	if (*res == 0)
	{
		ft_printf("%s\n", *msg);
		free(*msg);
		*msg = NULL;
		if (kill(pid, SIGUSR2) == -1)
			exit(EXIT_FAILURE);
	}
	*res = 0;
	*counter = 0;
}

static void	ft_reset_message_state(char **msg, int *counter, int *res)
{
	if (*msg != NULL)
	{
		free(*msg);
		*msg = NULL;
	}
	*counter = 0;
	*res = 0;
}

static void	ft_add_char_to_str(char c, char **str)
{
	char	*char_str;
	char	*temp;

	char_str = (char *)malloc(2);
	if (char_str == NULL)
		exit(EXIT_FAILURE);
	char_str[0] = c;
	char_str[1] = '\0';
	if (*str == NULL)
		*str = char_str;
	else
	{
		temp = ft_strjoin(*str, char_str);
		free(*str);
		free(char_str);
		if (temp == NULL)
			exit(EXIT_FAILURE);
		*str = temp;
	}
}

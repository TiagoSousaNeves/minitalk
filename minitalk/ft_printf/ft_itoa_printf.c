/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:35:39 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/08/07 02:39:19 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_printf(int n, char *start);
static void	ft_handle_exceptions(long long int *num, char **str);
static void	ft_true_itoa(long num, char *str, int sig);
static void	ft_handle_flag(char **str, char *start, int n);
static char	*ft_reverse_string(char *str, int len, int sig);

char	*ft_itoa_printf(int n, char *start)
{
	char			*str;
	long long int	num;
	int				sig;
	int				len;

	num = (long long int)n;
	sig = 0;
	str = NULL;
	ft_handle_exceptions(&num, &str);
	if (str == NULL)
	{
		len = ft_intlen(num);
		if (num < 0)
		{
			sig = 1;
			num = -num;
		}
		str = malloc(len + 1);
		if (str == NULL)
			return (NULL);
		ft_true_itoa(num, str, sig);
		ft_reverse_string(str, len, sig);
	}
	ft_handle_flag(&str, start, n);
	return (str);
}

static void	ft_handle_exceptions(long long int *num, char **str)
{
	if (*num == INT_MIN)
	{
		free(*str);
		*str = ft_strdup("-2147483648");
	}
	else if (*num > INT_MAX)
		*num = -1;
	else if (*num < INT_MIN)
		*num = 0;
}

static void	ft_true_itoa(long num, char *str, int sig)
{
	int		i;
	long	res;

	i = 0;
	if (sig == 1)
		str[i++] = '-';
	while (num > 9)
	{
		res = num % 10;
		str[i] = res + '0';
		num = num / 10;
		i++;
	}
	if (num <= 9)
		str[i++] = num + '0';
	str[i] = '\0';
}

static void	ft_handle_flag(char **str, char *start, int n)
{
	char	*temp;

	temp = NULL;
	if (*(start + 1) == ' ' && n >= 0)
	{
		if (*(start + 2) == '+')
			temp = ft_strjoin("+", *str);
		else
			temp = ft_strjoin(" ", *str);
		free(*str);
		*str = ft_strdup(temp);
	}
	else if (*(start + 1) == '+' && n >= 0)
	{
		temp = ft_strjoin("+", *str);
		free(*str);
		*str = ft_strdup(temp);
	}
	free(temp);
}

static char	*ft_reverse_string(char *str, int len, int sig)
{
	int		i;
	char	temp;
	int		tam;

	tam = len - 1;
	i = sig;
	while (i <= len / 2 && i < tam)
	{
		temp = str[i];
		str[i] = str[tam];
		str[tam] = temp;
		i++;
		tam--;
	}
	return (str);
}

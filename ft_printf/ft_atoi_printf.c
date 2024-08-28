/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 03:17:06 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi_printf(const char *ptr)
{
	int				i;
	int				sig;
	long long int	res;

	i = 0;
	sig = 1;
	res = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == ' ' || ptr[i] == '.')
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sig = -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		res *= 10;
		res += (ptr[i] - '0');
		i++;
	}
	return (res * sig);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_to_do.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 03:23:16 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_what_to_do(char boss)
{
	if (boss == '+')
		return (1);
	if (boss == ' ')
		return (2);
	if (boss == '0')
		return (3);
	if (boss == '-')
		return (4);
	if (boss == '.')
		return (5);
	if (boss == '#')
		return (6);
	if (boss == 'c')
		return (7);
	if (boss == 's')
		return (8);
	if (boss == 'p')
		return (9);
	if (boss == 'x' || boss == 'X')
		return (10);
	if (boss == 'd' || boss == 'i')
		return (11);
	if (boss == 'u')
		return (12);
	return (0);
}

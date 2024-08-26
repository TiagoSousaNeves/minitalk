/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_nb_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:32:59 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base_nb_len(long long unsigned int num, long long unsigned int base)
{
	long long unsigned int	size;

	size = 0;
	if (num == 0)
		return (1);
	if (num < size)
		return (-1);
	if (num >= base)
		size = ft_base_nb_len(num / base, base);
	size++;
	return (size);
}

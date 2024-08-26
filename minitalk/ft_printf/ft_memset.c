/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:14:50 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:10:05 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	while (n > 0)
	{
		ptr[i] = (unsigned char)c;
		n--;
		i++;
	}
	return (str);
}

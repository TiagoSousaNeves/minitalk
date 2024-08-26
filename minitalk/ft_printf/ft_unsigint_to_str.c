/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigint_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:14:58 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_unsigint_to_str(unsigned int num);
static void	ft_fill_str_with_digits(char **str, unsigned int num,
				unsigned int size);

char	*ft_unsigint_to_str(unsigned int num)
{
	char			*str;
	unsigned int	size;
	unsigned int	max;
	unsigned int	min;

	max = 4294967295;
	min = 0;
	size = ft_uintlen(num);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (num < min)
		num = max - (num);
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	ft_fill_str_with_digits(&str, num, size);
	return (str);
}

static void	ft_fill_str_with_digits(char **str, unsigned int num,
		unsigned int size)
{
	char	c;

	while (num > 0 && size > 0)
	{
		size--;
		c = num % 10 + '0';
		(*str)[size] = c;
		num /= 10;
	}
	return ;
}

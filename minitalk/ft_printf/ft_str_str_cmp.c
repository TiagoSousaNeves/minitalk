/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_str_cmp.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:37:03 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/10 16:35:26 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_str_cmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str1 || !str2)
		return (NULL);
	while (str1[i] && i < n)
	{
		j = 0;
		while (str2[j] && i < n)
		{
			if (str1[i] == str2[j])
				return ((char *)&str1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

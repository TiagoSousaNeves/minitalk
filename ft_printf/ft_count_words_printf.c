/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:22:38 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_words_printf(const char *s, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		if (s[i] == c)
			i++;
		while ((s[i] >= '0' && s[i] <= '9') || (ft_chr_str_cmp(s[i], "+# -.")))
			i++;
		if ((ft_chr_str_cmp(s[i], "cspdiuxX%") && i < strlen(s)))
			i++;
		if (s[i] != '\0')
			count++;
		if (s[i] == '\0' && (ft_chr_str_cmp(s[i - 1], "cspdiuxX%")))
			count++;
	}
	return (count);
}

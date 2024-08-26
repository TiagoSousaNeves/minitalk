/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 07:05:55 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_hexa_to_str(unsigned int num, char **str, int size, char *start);
static void	ft_handle_prefix(char ***str, int *n, char *boss);

void	ft_hexa_to_str(unsigned int num, char **str, int size, char *start)
{
	char	hexa[16];
	char	c;
	char	*boss;
	int		i;
	int		n;

	boss = ft_str_str_cmp(start, "cspdiuxX", ft_strlen(start));
	n = 0;
	ft_strlcpy(hexa, "0123456789abcdef", 17);
	i = size - 1;
	if (num == 0)
		(*str)[0] = '0';
	else if (*(start + 1) == '#' || *(start + 2) == '#')
		ft_handle_prefix(&str, &n, boss);
	while (num > 0 && i >= n)
	{
		c = hexa[num % 16];
		if (*boss == 'X')
			c = ft_toupper(c);
		(*str)[i] = c;
		num /= 16;
		i--;
	}
	(*str)[size] = '\0';
	return ;
}

static void	ft_handle_prefix(char ***str, int *n, char *boss)
{
	(**str)[0] = '0';
	(**str)[1] = 'x';
	if (*boss == 'X')
		(**str)[1] = ft_toupper((**str)[1]);
	*n = 2;
	return ;
}

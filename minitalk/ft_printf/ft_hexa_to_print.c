/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_to_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:36:06 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa_to_print(unsigned int num, char *start)
{
	char	*str;
	int		size;

	str = NULL;
	if ((*(start + 1) == '#' || *(start + 2) == '#') && num != 0)
		size = ft_base_nb_len(num, 16) + 2;
	else
		size = ft_base_nb_len(num, 16);
	str = malloc(((size) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_bzero_printf(str, size);
	ft_hexa_to_str(num, &str, size, start);
	return (str);
}

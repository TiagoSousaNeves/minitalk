/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_callocate_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:05:53 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_callocate_string(int len)
{
	char	*str;

	str = (char *)ft_calloc_printf(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	return (str);
}

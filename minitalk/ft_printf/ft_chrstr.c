/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:31:27 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_chrstr(int c)
{
	char	*ptr;
	char	l;

	l = (char)c;
	if (c == '\0')
		return (ft_strdup(".\a*"));
	ptr = malloc(2);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = l;
	ptr[1] = '\0';
	return (ptr);
}

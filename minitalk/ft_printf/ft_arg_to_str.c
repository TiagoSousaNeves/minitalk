/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:14:29 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_arg_to_str(va_list args, char *boss, char *start)
{
	char	*arg_str;

	arg_str = NULL;
	if (*boss == 'c')
		arg_str = ft_chrstr((char)va_arg(args, int));
	else if (*boss == 'i' || *boss == 'd')
		arg_str = ft_itoa_printf(va_arg(args, int), start);
	else if (*boss == 's')
	{
		arg_str = (char *)va_arg(args, char *);
		if (arg_str == NULL)
			arg_str = ft_strdup("(null)");
		else
			arg_str = ft_strdup(arg_str);
	}
	else if (*boss == 'u')
		arg_str = ft_unsigint_to_str(va_arg(args, unsigned int));
	else if (*boss == 'p')
		arg_str = ft_ptr_to_str(va_arg(args, void *), start);
	else if (*boss == '%')
		arg_str = ft_chrstr('%');
	else if (*boss == 'x' || *boss == 'X')
		arg_str = ft_hexa_to_print(va_arg(args, int), start);
	return (arg_str);
}

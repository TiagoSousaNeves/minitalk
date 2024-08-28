/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_aux_negative.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 02:13:32 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_aux_negative(char ********to_print, char **str, int aux)
{
	char	*temp;

	if ((******to_print)[0][1] != '0')
	{
		if (aux == INT_MIN)
		{
			free(*******to_print);
			(*******to_print) = ft_strdup("2147483648");
		}
		else
		{
			free(*******to_print);
			*******to_print = ft_itoa_printf(-aux, "-");
		}
	}
	temp = ft_strjoin("-", *str);
	free(*str);
	*str = ft_strjoin(temp, *******to_print);
	free(temp);
	free(*******to_print);
	*******to_print = ft_strdup(*str);
	free(*str);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_positive_plus_or_space.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:04:47 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 03:39:30 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_positive_plus_or_space(char ********to_print, char *start,
				char *str, int aux);
static void	ft_handle_aux_positive_and_plus(char *********to_print, char *str,
				int aux);

void	ft_handle_positive_plus_or_space(char ********to_print, char *start,
		char *str, int aux)
{
	if (aux > 0 && ********to_print == '+')
		ft_handle_aux_positive_and_plus(&to_print, str, aux);
	else if (aux > 0 && ********to_print == ' ')
		ft_handle_space(*****&to_print, start, str, aux);
	return ;
}

static void	ft_handle_aux_positive_and_plus(char *********to_print, char *str,
		int aux)
{
	char	*temp;

	if (aux > 0 && *********to_print == '+')
	{
		free(********to_print);
		********to_print = ft_itoa_printf(aux, "nada");
		temp = ft_strjoin("+", str);
		free(str);
		str = ft_strjoin(temp, ********to_print);
		free(temp);
		free(********to_print);
		********to_print = ft_strdup(str);
		free(str);
	}
	return ;
}

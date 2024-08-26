/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 06:56:18 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_plus(char *str_width, char ****temp_print, char *end)
{
	char	**split_result;
	char	*temp_concat;
	char	*temp;

	temp = ft_strdup(***temp_print);
	if (*end == 'i' || *end == 'u' || *end == 'd' || *end == 'p')
	{
		split_result = ft_split_printf(temp, '+');
		free(temp);
		temp_concat = ft_strjoin(str_width, split_result[0]);
		free(str_width);
		free(split_result[0]);
		***temp_print = ft_strjoin("+", temp_concat);
		free(temp_concat);
		free(split_result);
	}
	else
	{
		***temp_print = ft_strjoin(str_width, temp);
		free(temp);
		free(str_width);
	}
}

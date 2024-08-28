/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_end_p_or_xs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:57:10 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_end_p_or_xs(char ********to_print, char *str, char *end);
static void	ft_handle_end_x_or_p(char *********to_print, char *str);
static void	ft_handle_end_xbig(char *********to_print, char *str);

void	ft_handle_end_p_or_xs(char ********to_print, char *str, char *end)
{
	if (*end == 'X')
	{
		ft_handle_end_xbig(&to_print, str);
	}
	else if (*end == 'x' || *end == 'p')
	{
		ft_handle_end_x_or_p(&to_print, str);
	}
}

static void	ft_handle_end_x_or_p(char *********to_print, char *str)
{
	char	*temp;

	temp = ft_strtrim(********to_print, "0x");
	free(********to_print);
	********to_print = ft_strjoin(str, temp);
	free(temp);
	free(str);
	str = ft_strjoin("0x", ********to_print);
	free(********to_print);
	********to_print = ft_strdup(str);
	free(str);
}

static void	ft_handle_end_xbig(char *********to_print, char *str)
{
	char	*temp;

	temp = ft_strtrim(********to_print, "0X");
	free(********to_print);
	********to_print = ft_strjoin(str, temp);
	free(temp);
	free(str);
	str = ft_strjoin("0X", ********to_print);
	free(********to_print);
	********to_print = ft_strdup(str);
	free(str);
}

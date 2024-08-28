/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 06:42:51 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_zero(char ********to_print, char *start, char *boss,
				char *str_width);
static void	ft_handle_negative(char **temp_print, char *str_width,
				long long int aux, char *start);

void	ft_handle_zero(char ********to_print, char *start, char *boss,
		char *str_width)
{
	long long int	aux;
	char			*end;
	char			*temp;
	char			**temp_print;

	aux = 0;
	end = ft_str_str_cmp(boss, "cspdiuxX", ft_strlen(boss));
	temp_print = ******to_print;
	temp = ft_strdup(*temp_print);
	free(*temp_print);
	if (*boss == *start && *boss == '0')
	{
		if (*end == 'i' || *end == 'd')
			aux = ft_atoi_printf(temp);
		if (aux < 0 && temp[2] != '0' && *str_width == '0')
		{
			ft_handle_negative(temp_print, str_width, aux, start);
			free(temp);
			return ;
		}
		*temp_print = ft_strjoin(str_width, temp);
		free(str_width);
		free(temp);
	}
}

static void	ft_handle_negative(char **temp_print, char *str_width,
		long long int aux, char *start)
{
	char	*temp;

	if (aux == INT_MIN)
		*temp_print = ft_strdup("2147483648");
	else
		*temp_print = ft_itoa_printf(-aux, start);
	temp = ft_strjoin("-", str_width);
	free(str_width);
	str_width = ft_strjoin(temp, *temp_print);
	free(temp);
	free(*temp_print);
	*temp_print = ft_strdup(str_width);
	free(str_width);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:15:26 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 03:32:07 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_apply_precision(char *******to_print, size_t precision,
				char *end, char *start);
static void	ft_ajust_len(char *to_print, char *start, char end, int *len);
static void	ft_handle_to_print(char ********to_print, int precision, char *end);
static void	ft_handle_len_and_print_s(char ********to_print, int len, char *end,
				int precision);
static void	ft_ajust_len_for_sign(char *to_print, long long int *aux, int *len,
				char end);

void	ft_apply_precision(char *******to_print, size_t precision, char *end,
		char *start)
{
	char			*str;
	int				len;
	long long int	aux;

	str = NULL;
	aux = 0;
	len = precision - ft_strlen((const char *)(******to_print));
	ft_ajust_len(******to_print, start, *end, &len);
	if (!(ft_strncmp(******to_print, "(nil)", ft_strlen(******to_print))))
		return ;
	ft_handle_to_print(&to_print, precision, end);
	ft_handle_len_and_print_s(&to_print, len, end, precision);
	if (len >= 0 && *(end) != 's')
	{
		ft_ajust_len_for_sign(******to_print, &aux, &len, *end);
		str = ft_callocate_string(len);
		if (aux < 0)
			ft_handle_aux_negative(&to_print, &str, aux);
		else if (*end == 'p' || *start == '#' || *(start + 1) == '#')
			ft_handle_end_p_or_xs(&to_print, str, end);
		else if (aux > 0 && (*******to_print == '+' || *******to_print == ' '))
			ft_handle_positive_plus_or_space(&to_print, start, str, aux);
		else
			ft_handle_default_condition(&to_print, str);
	}
}

static void	ft_ajust_len(char *to_print, char *start, char end, int *len)
{
	if (ft_strnstr_printf((const char *)to_print, ".\a*", ft_strlen(to_print)))
		*len += 2;
	if (*to_print == '+')
		*len += 1;
	if (end == 'p' || *start == '#' || *(start + 1) == '#')
		*len += 2;
	if (*start == ' ' && ft_isdigit(*(start + 1)))
		*len += 1;
	return ;
}

static void	ft_handle_to_print(char ********to_print, int precision, char *end)
{
	char	*str;

	str = NULL;
	if (ft_strrchr_printf(*******to_print, '0')
		&& ft_strlen(*******to_print) == 1 && precision == 0 && *end != 'c')
	{
		free(*******to_print);
		*******to_print = ft_strdup("");
		return ;
	}
	if (*(end - 1) == '.' && !ft_isdigit(*(end - 2)) && *end == 's')
	{
		free(*******to_print);
		*******to_print = ft_strdup("");
		return ;
	}
	if (!(ft_strncmp(*******to_print, "(null)", ft_strlen(*******to_print)))
		&& (precision < 6))
	{
		str = ft_strdup("");
		free(*******to_print);
		*******to_print = ft_strdup(str);
		free(str);
	}
}

static void	ft_handle_len_and_print_s(char ********to_print, int len, char *end,
		int precision)
{
	char	*str;

	str = NULL;
	if (len < 0 && *end == 's')
	{
		str = ft_strndup(*******to_print, precision);
		free(*******to_print);
		*******to_print = ft_strdup(str);
		free(str);
	}
	return ;
}

static void	ft_ajust_len_for_sign(char *to_print, long long int *aux, int *len,
		char end)
{
	if (end == 'i' || end == 'd')
	{
		*aux = ft_atoi_printf((const char *)to_print);
		if (*aux < 0)
			(*len)++;
	}
	return ;
}

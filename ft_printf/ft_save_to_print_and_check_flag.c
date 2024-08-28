/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_to_print_and_check_flag.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:37:21 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_save_to_print_and_check_flag(va_list args, char *format,
				char ***to_print);
static void	ft_handle_percent_format(va_list args, char ****to_print,
				char **start, char **boss);
static void	ft_save_non_format_part(char **start, char **boss,
				char ****to_print);

void	ft_save_to_print_and_check_flag(va_list args, char *format,
		char ***to_print)
{
	char	*boss;
	char	*start;

	boss = format;
	start = format;
	while (*boss)
	{
		if (start != boss)
			start = boss;
		while (*boss && *boss != '%')
			boss++;
		if (*boss == '%' || !*boss)
			ft_save_non_format_part(&start, &boss, &to_print);
		if (*start == '%')
		{
			ft_handle_percent_format(args, &to_print, &start, &boss);
			if (boss == NULL)
			{
				**to_print = NULL;
				return ;
			}
			(*to_print)++;
		}
	}
	**to_print = NULL;
}

static void	ft_save_non_format_part(char **start, char **boss,
		char ****to_print)
{
	if (**boss == '%' || !**boss)
	{
		if (!(**start == **boss))
		{
			***to_print = ft_strndup(*start, *boss - *start);
			if (!***to_print)
				return ;
			(**to_print)++;
		}
		*start = *boss;
		(*boss) += (**boss != '\0' && **boss != '%');
	}
}

static void	ft_handle_percent_format(va_list args, char ****to_print,
		char **start, char **boss)
{
	if (**start == '%')
	{
		*boss = ft_str_str_cmp((*start + 1), "cspdiuxX%*", ft_strlen(*start));
		if (*boss == NULL)
		{
			***to_print = ft_strdup("%");
			if (!***to_print)
				return ;
			(**to_print)++;
			*start = *boss;
			return ;
		}
		else if (**boss == '*')
		{
			***to_print = ft_strdup("*");
			if (!***to_print)
				return ;
			*start = *boss;
			(boss)++;
			ft_handle_percent_format(args, to_print, start, boss);
			return ;
		}
		else
			ft_check_what_to_do(args, &boss, &start, &to_print);
	}
}

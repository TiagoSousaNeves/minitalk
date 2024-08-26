/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fill_width_organize_to_print.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:45:16 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:36:16 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_fill_width_organize_to_print(char ******to_print,
				char ****boss, char ****start);
static int	ft_go_back_for_width(char *****boss, char *start, char *to_print);
static char	*ft_how_to_fill_width(char *****boss, char *start, int width);
static char	*ft_handle_width_conditions(char ******boss, char *start,
				char *str_width, int width);
static char	*ft_handle_width_conditions(char ******boss, char *start,
				char *str_width, int width);

void	ft_check_fill_width_organize_to_print(char ******to_print,
		char ****boss, char ****start)
{
	int		width;
	char	*str_width;

	width = 0;
	str_width = NULL;
	if (****(boss - 1) == '.')
		**(*boss) -= 2;
	if (***boss >= ***start)
		width = ft_go_back_for_width(&boss, ***start, *****to_print);
	if (width)
	{
		str_width = ft_how_to_fill_width(&boss, ***start, width);
		ft_organize_to_print(&to_print, &boss, ***start, str_width);
	}
	return ;
}

static int	ft_go_back_for_width(char *****boss, char *start, char *to_print)
{
	int	width;
	int	num;

	width = 0;
	if (!(ft_isdigit(*****boss)))
		(****boss)--;
	if (*****boss == '%')
		return (width);
	while (ft_isdigit(*****boss) && ****boss > start)
		(****boss)--;
	if ((ft_isdigit((*****boss))))
		num = ft_atoi_printf(****boss);
	else
		num = ft_atoi_printf(***(*boss) + 1);
	if (num < 0)
		num = -num;
	width = num - ft_strlen((const char *)(to_print));
	if (ft_strnstr_printf(to_print, ".\a*", ft_strlen(to_print)))
		width += 2;
	if (*start == ' ' && ft_strncmp(to_print, "", 1) && *****boss != '+'
		&& *****boss != '#' && !ft_isdigit(*(start + 1)) && *****boss != '-')
		width += 1;
	if (width < 0)
		return (0);
	return (width);
}

static char	*ft_how_to_fill_width(char *****boss, char *start, int width)
{
	char	*str_width;

	str_width = NULL;
	if (width > 0)
	{
		str_width = malloc(sizeof(char) * (width + 1));
		if (!str_width)
			return (NULL);
		str_width[width] = '\0';
	}
	str_width = ft_handle_width_conditions(&boss, start, str_width, width);
	return (str_width);
}

static char	*ft_handle_width_conditions(char ******boss, char *start,
		char *str_width, int width)
{
	char	*end;

	end = ft_str_str_cmp(*****boss, "cspdiuxX", ft_strlen(*****boss));
	if (******boss == '.' && *(end - 1) != 's')
		ft_bzero_printf(str_width, width + 1);
	else if (*****boss >= start && ((******boss == '-' || *****(*boss
					- 1) == '-') && ******boss != '.'))
		ft_bspace_printf(str_width, width + 1);
	else if ((*****boss == start && ******boss == '0') || (*****(*boss
				+ 1) == '0' && (*start == '#' || *start == '+'
				|| *start == ' ')))
	{
		if (ft_chr_str_cmp(*end, "sdcixXu"))
			ft_handle_specifier(*****boss, end, &str_width, width);
		else
			ft_bzero_printf(str_width, width + 1);
	}
	else if ((*****boss == start) && (******boss == ' '
			|| ft_ispositive(******boss) || ******boss == '#'))
		ft_bspace_printf(str_width, width + 1);
	else if (*****boss >= start && (******boss == '+' || ******boss == '#'))
		ft_bspace_printf(str_width, width + 1);
	return (str_width);
}

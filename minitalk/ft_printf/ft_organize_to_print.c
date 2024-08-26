/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize_to_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 06:37:48 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_organize_to_print(char *******to_print, char *****boss,
				char *start, char *str_width);
static void	ft_handle_default(char ***temp_print, char *temp, char *str_width);
static void	ft_handle_digit(char ***temp_print, char *str_width, char *boss,
				char *start);
static void	ft_handle_dash(char ***temp_print, char *str_width, char *boss,
				char *start);
static void	ft_handle_flags(char ***temp_print, char *start, char *boss,
				char *str_width);

void	ft_organize_to_print(char *******to_print, char *****boss, char *start,
		char *str_width)
{
	char	*temp;
	char	**temp_print;
	char	*end;

	temp_print = *****to_print;
	temp = ft_strdup(*temp_print);
	end = ft_str_str_cmp(****boss, "cspdiuxX", ft_strlen(****boss));
	if (****boss >= start && *****boss == '.')
		ft_handle_dot(&to_print, start, ****boss, str_width);
	else if (****boss == start && *****boss == '0')
		ft_handle_zero(&to_print, start, ****boss, str_width);
	else if ((****boss >= start && *****(boss - 1) == '-' && *****boss != '.')
		|| (*****boss == '-'))
		ft_handle_dash(&temp_print, str_width, ****boss, start);
	else if ((*****boss == '0' || ***(**boss + 1) == '0' || *start == ' ')
		&& *end != 's' && *****boss != '#')
		ft_handle_flags(&temp_print, start, ****boss, str_width);
	else if (****boss == start && (ft_ispositive(*****boss)
			|| ft_ispositive(***(**boss + 1))))
		ft_handle_digit(&temp_print, str_width, ****boss, start);
	else if (str_width)
		ft_handle_default(&temp_print, temp, str_width);
	free(temp);
	return ;
}

static void	ft_handle_default(char ***temp_print, char *temp, char *str_width)
{
	if (str_width)
	{
		free(**temp_print);
		**temp_print = ft_strjoin(str_width, temp);
		free(str_width);
	}
}

static void	ft_handle_digit(char ***temp_print, char *str_width, char *boss,
		char *start)
{
	char	*temp;

	if (boss == start && (ft_ispositive(*boss) || ft_ispositive(*(boss + 1))))
	{
		temp = ft_strdup(**temp_print);
		free(**temp_print);
		**temp_print = ft_strjoin(str_width, temp);
		free(temp);
		free(str_width);
	}
}

static void	ft_handle_dash(char ***temp_print, char *str_width, char *boss,
		char *start)
{
	char	*temp;

	if ((boss >= start && *(boss - 1) == '-' && *boss != '.') || (*boss == '-'))
	{
		temp = ft_strdup(**temp_print);
		free(**temp_print);
		**temp_print = ft_strjoin(temp, str_width);
		free(temp);
		free(str_width);
	}
}

static void	ft_handle_flags(char ***temp_print, char *start, char *boss,
		char *str_width)
{
	char	*end;
	int		aux;

	aux = 0;
	end = ft_str_str_cmp(boss, "cspdiuxX", ft_strlen(boss));
	if ((*end == 'x' || *end == 'X') && (*start == '#') && ((*(boss + 1) == '0'
				|| (*(boss + 1) == '.')) && *str_width))
		ft_handle_space_and_zero(&temp_print, start, boss, str_width);
	else if ((*start == ' ' || *start == '+') && str_width)
	{
		aux = ft_atoi_printf(**temp_print);
		if (*start == ' ')
			ft_handle_space(&temp_print, start, str_width, aux);
		else if (*start == '+')
			ft_handle_plus(str_width, &temp_print, end);
	}
}

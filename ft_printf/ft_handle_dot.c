/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 06:39:51 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_dot(char ********to_print, char *start, char *boss,
				char *str_width);
static void	ft_handle_hash(char **temp_print, char *temp, char *str_width,
				char end_char);

void	ft_handle_dot(char ********to_print, char *start, char *boss,
		char *str_width)
{
	char	*end;
	char	*temp;
	char	**temp_print;

	end = ft_str_str_cmp(boss, "cspdiuxX", ft_strlen(boss));
	temp_print = ******to_print;
	temp = ft_strdup(*temp_print);
	free(*temp_print);
	if (*boss >= *start && *boss == '.')
	{
		if (*start == '#')
		{
			ft_handle_hash(temp_print, temp, str_width, *end);
		}
		else
		{
			*temp_print = ft_strjoin(str_width, temp);
			free(temp);
			free(str_width);
		}
	}
	return ;
}

static void	ft_handle_hash(char **temp_print, char *temp, char *str_width,
		char end_char)
{
	char	**split_temp;
	char	*joined_temp;

	split_temp = ft_split_printf(temp, end_char);
	if (end_char == 'X')
		joined_temp = ft_strjoin(split_temp[0], "X");
	else
		joined_temp = ft_strjoin(split_temp[0], "x");
	*temp_print = ft_strjoin(joined_temp, str_width);
	free(joined_temp);
	joined_temp = ft_strjoin(temp_print[0], split_temp[1]);
	free(*temp_print);
	*temp_print = joined_temp;
}

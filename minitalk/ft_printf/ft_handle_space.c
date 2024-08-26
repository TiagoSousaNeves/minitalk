/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 06:45:58 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:47:12 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_space(char ****temp_print, char *start, char *str_width,
				int aux);
static void	ft_handle_positive_aux(char *****temp_print, char *temp,
				char *str_width);
static void	ft_handle_negative_aux(char **temp, char *start, char *str_width,
				int aux);

void	ft_handle_space(char ****temp_print, char *start, char *str_width,
		int aux)
{
	char	*temp;

	temp = ft_strdup(***temp_print);
	free(***temp_print);
	if (*start == ' ' && *(start + 1) != '+' && *(start + 1) != '#')
	{
		if (aux > 0)
			ft_handle_positive_aux(&temp_print, temp, str_width);
		else if (aux < 0)
		{
			ft_handle_negative_aux(&temp, start, str_width, aux);
			***temp_print = ft_strdup(temp);
		}
		else
			***temp_print = ft_strdup(temp);
	}
	else
	{
		***temp_print = ft_strjoin(str_width, temp);
		free(temp);
		free(str_width);
	}
}

static void	ft_handle_positive_aux(char *****temp_print, char *temp,
		char *str_width)
{
	char	**split_result;
	char	*temp_concat;

	split_result = ft_split_printf(temp, ' ');
	free(temp);
	temp_concat = ft_strjoin(str_width, split_result[0]);
	free(str_width);
	free(split_result[0]);
	****temp_print = ft_strjoin(" ", temp_concat);
	free(temp_concat);
	free(split_result);
	return ;
}

static void	ft_handle_negative_aux(char **temp, char *start, char *str_width,
		int aux)
{
	char	*temp_temp;
	char	*new_str_width;

	temp_temp = ft_itoa_printf(-aux, start);
	new_str_width = ft_strjoin("-0", str_width);
	free(str_width);
	*temp = ft_strjoin(new_str_width, temp_temp);
	free(new_str_width);
	free(temp_temp);
	return ;
}

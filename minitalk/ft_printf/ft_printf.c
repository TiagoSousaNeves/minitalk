/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:51:21 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...);
static void	ft_malloc_for_to_print(char *format, char ***to_print);
static char	*ft_strjoin_to_print(char ***start_to_print);
static int	ft_putstr_printf(char *str);
static void	ft_putstr_coded(const char *str, size_t *size, char c);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	**to_print;
	char	**start_to_print;
	char	*print;
	int		i;

	if (*format == '\0')
		return (0);
	to_print = NULL;
	va_start(args, format);
	ft_malloc_for_to_print((char *)format, &to_print);
	start_to_print = to_print;
	ft_save_to_print_and_check_flag(args, (char *)format, &to_print);
	print = ft_strjoin_to_print(&start_to_print);
	i = 0;
	while (start_to_print[i])
	{
		free(start_to_print[i]);
		i++;
	}
	free(start_to_print);
	va_end(args);
	i = ft_putstr_printf(print);
	free(print);
	return (i);
}

static void	ft_malloc_for_to_print(char *format, char ***to_print)
{
	int	i;
	int	count;

	i = 0;
	count = ft_count_words_printf(format, '%') + 1;
	*to_print = malloc(count * sizeof(char *));
	if (*to_print == NULL)
		return ;
	while (i < count)
	{
		(*to_print)[i] = NULL;
		i++;
	}
	return ;
}

static char	*ft_strjoin_to_print(char ***start_to_print)
{
	int		i;
	char	*print;
	char	*temp;
	char	*new_print;

	i = 0;
	print = NULL;
	while ((*start_to_print)[i])
	{
		temp = ft_strdup((*start_to_print)[i]);
		if (!temp)
			return (NULL);
		if (!print)
			print = temp;
		else
		{
			new_print = ft_strjoin(print, temp);
			free(print);
			free(temp);
			print = new_print;
		}
		i++;
	}
	return (print);
}

static int	ft_putstr_printf(char *str)
{
	char	c;
	size_t	size;

	size = 0;
	c = '\0';
	if (str)
		size = ft_strlen(str);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_coded(str, &size, c);
	return (size);
}

static void	ft_putstr_coded(const char *str, size_t *size, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == '\a' && str[i + 2] == '*')
		{
			write(1, &c, 1);
			i += 3;
			*size -= 2;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:00:18 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_ptr_to_str(void *ptr, char *start);
static void	ft_ptr_to_str_part2(long long unsigned int num, char **str,
				int size);
static void	ft_define_size(const char *start, int *size,
				long long unsigned int num);

char	*ft_ptr_to_str(void *ptr, char *start)
{
	long long unsigned int	num;
	char					*str;
	int						size;

	size = 0;
	if (ptr == NULL)
		return (ft_strdup("(nil)"));
	num = (long long unsigned int)ptr;
	ft_define_size(start, &size, num);
	str = malloc(((size) + 1) * sizeof(char));
	str[size] = '\0';
	if (str == NULL)
		return (NULL);
	if (*(start + 1) == '+')
		ft_memcpy(str, "+0x", 3);
	else if (*(start + 1) == ' ')
		ft_memcpy(str, " 0x", 3);
	else if (*(start + 1) == ' ' && *(start + 2) == '+')
		ft_memcpy(str, " +0x", 4);
	else
		ft_memcpy(str, "0x", 2);
	ft_ptr_to_str_part2(num, &str, size);
	return (str);
}

static void	ft_ptr_to_str_part2(long long unsigned int num, char **str,
		int size)
{
	char	hexa[16];
	char	c;
	int		i;

	ft_strlcpy(hexa, "0123456789abcdef", 17);
	i = size - 1;
	while (num > 0 && i >= 0)
	{
		c = hexa[num % 16];
		(*str)[i] = c;
		num /= 16;
		i--;
	}
	return ;
}

void	ft_define_size(const char *start, int *size, long long unsigned int num)
{
	if (*(start + 1) == '+' || *(start + 1) == ' ')
		*size = 1;
	if (*(start + 1) == ' ' && *(start + 2) == '+')
		*size = 2;
	*size += ft_base_nb_len(num, 16) + 2;
	return ;
}

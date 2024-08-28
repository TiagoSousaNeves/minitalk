/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:05:09 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/05/28 02:09:45 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		**ft_split_printf(const char *s, char c);
static int	ft_count_words(const char *s, char c);
static int	ft_count_letter(char *s, char c);
static int	ft_strlcpy_for_split(char *dst, const char *src, unsigned int size);
static int	ft_fill_strings(const char *s, const char c, int a, char **strs);

char	**ft_split_printf(const char *s, char c)
{
	char	**strs;
	int		i;
	int		w;
	int		a;
	int		fill;

	i = 0;
	a = 0;
	fill = 0;
	w = ft_count_words(s, c);
	strs = malloc((w + w + ft_n_char_in_str(s, c)) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	while (a < w)
	{
		fill = ft_fill_strings(&s[i], c, a, &*strs);
		if (!fill)
			return (NULL);
		i = i + fill;
		a++;
	}
	strs[a] = NULL;
	return (strs);
}

static int	ft_count_words(const char *s, char c)
{
	int		w;
	size_t	i;

	w = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			w++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (w);
}

static int	ft_fill_strings(const char *s, char c, int a, char **strs)
{
	int	i;
	int	l;

	i = 0;
	while (s[i] == c)
		i++;
	l = ft_count_letter((char *)&s[i], c);
	if (l == 0)
		strs[a] = NULL;
	else
	{
		strs[a] = (char *)malloc((l + 1) * sizeof(char));
		if (strs[a] == NULL)
		{
			while (a--)
				free(strs[a]);
			free(strs);
			return (0);
		}
		i = i + ft_strlcpy_for_split(strs[a], &s[i], l + 1);
	}
	return (i);
}

static int	ft_count_letter(char *s, char c)
{
	int	l;

	l = 0;
	while (s[l] != c && s[l])
		l++;
	return (l);
}

static int	ft_strlcpy_for_split(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (i);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

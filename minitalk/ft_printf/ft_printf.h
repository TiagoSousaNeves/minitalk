/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 05:14:22 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/08/07 02:34:31 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <pthread.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
char	**ft_split_printf(const char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_str_str_cmp(const char *str1, const char *str2, size_t n);
int		ft_what_to_do(char boss);
char	*ft_strdup(const char *str);
char	*ft_itoa_printf(int n, char *start);
int		ft_uintlen(unsigned int num);
int		ft_intlen(int num);
char	*ft_ptr_to_str(void *ptr, char *start);
int		ft_base_nb_len(long long unsigned int num, long long unsigned int base);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
int		ft_toupper(int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_chrstr(int c);
char	*ft_strndup(const char *str, int n);
int		ft_n_char_in_str(const char *str, char c);
int		ft_ispositive(int c);
int		ft_isdigit(int c);
int		ft_atoi_printf(const char *ptr);
void	ft_bzero_printf(void *str, size_t n);
void	ft_bspace_printf(void *str, size_t n);
int		ft_strrchr_printf(const char *str, int c);
int		ft_count_words_printf(const char *str, char c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_calloc_printf(size_t count, size_t size);
char	*ft_strtrim(const char *s1, const char *set);
int		ft_chr_str_cmp(char c, const char *str);
int		ft_strnstr_printf(const char *big, const char *lit, size_t len);
char	*ft_callocate_string(int len);
void	ft_save_to_print_and_check_flag(va_list args, char *format,
			char ***to_print);
void	ft_check_what_to_do(va_list args, char ***boss, char ***start,
			char *****to_print);
void	ft_check_fill_width_organize_to_print(char ******to_print,
			char ****boss, char ****start);
void	ft_organize_to_print(char *******to_print, char *****boss, char *start,
			char *str_width);
void	ft_handle_dot(char ********to_print, char *start, char *boss,
			char *str_width);
void	ft_handle_zero(char ********to_print, char *start, char *boss,
			char *str_width);
void	ft_apply_precision(char *******to_print, size_t precision, char *end,
			char *start);
void	ft_handle_aux_negative(char ********to_print, char **str, int aux);
void	ft_handle_space_and_zero(char ****temp_print, char *start, char *boss,
			char *str_width);
void	ft_handle_space(char ****temp_print, char *start, char *str_width,
			int aux);
void	ft_handle_end_p_or_xs(char ********to_print, char *str, char *end);
void	ft_hexa_to_str(unsigned int num, char **str, int size, char *start);
char	*ft_hexa_to_print(unsigned int num, char *start);
char	*ft_arg_to_str(va_list args, char *boss, char *start);
char	*ft_unsigint_to_str(unsigned int num);
void	ft_handle_plus(char *str_width, char ****temp_print, char *end);
void	ft_handle_default_condition(char ********to_print, char *str);
void	ft_handle_positive_plus_or_space(char ********to_print, char *start,
			char *str, int aux);
void	ft_handle_specifier(char *boss, char *end, char **str_width,
			size_t width);
#endif

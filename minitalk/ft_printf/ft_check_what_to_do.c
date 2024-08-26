/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_check_what_to_do.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfelguei <tfelguei.students.42porto.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/05/21 09:16:02 by tcosta-f		  #+#	#+#			 */
/*   Updated: 2024/05/24 16:36:09 by tfelguei		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_what_to_do(va_list args, char ***boss, char ***start,
				char *****to_print);
static char	*ft_start_to_do(va_list args, char ******to_print, char ****start,
				char ****boss);
static char	*ft_handle_dot_exceptions_and_go(char ******to_print, char ****boss,
				char ****start, char *task_str);
static void	ft_handle_precision(char ******to_print, char ****boss,
				char ****start, char **end);
static int	ft_go_back_for_precision(char *****boss, char *****start);

void	ft_check_what_to_do(va_list args, char ***boss, char ***start,
		char *****to_print)
{
	char	*task_str;
	char	*end;

	end = ft_start_to_do(args, &to_print, &start, &boss);
	if (end == NULL)
		return ;
	task_str = ft_strndup(**start, (end - **start));
	if (ft_strrchr_printf(task_str, '.') || ft_isdigit(*(**boss - 1)))
	{
		end = ft_handle_dot_exceptions_and_go(&to_print, &boss, &start,
				task_str);
		ft_handle_precision(&to_print, &boss, &start, &end);
		ft_check_fill_width_organize_to_print(&to_print, &boss, &start);
	}
	if (*(end + 1))
	{
		end = ft_str_str_cmp(end, "cspdiuxX%", ft_strlen(end));
		if (end != NULL)
			end++;
	}
	else
		end++;
	**boss = end;
	**start = end;
	free(task_str);
}

static char	*ft_start_to_do(va_list args, char ******to_print, char ****start,
		char ****boss)
{
	int		flag;
	char	*arg_str;
	char	*end;

	end = NULL;
	flag = ft_what_to_do(****boss);
	if (flag >= 7 || ****boss == '%')
	{
		arg_str = ft_arg_to_str(args, ***boss, ***start);
		if (*arg_str == '%' && flag != 7)
		{
			end = (***boss)++;
			***start = end;
			free(*****to_print);
			*****to_print = ft_strndup(arg_str, ft_strlen(arg_str));
			free(arg_str);
			return (end);
		}
		*****to_print = ft_strdup(arg_str);
		free(arg_str);
		if (!**to_print)
			return (NULL);
		(***start)++;
	}
	return (end = ***boss);
}

static char	*ft_handle_dot_exceptions_and_go(char ******to_print, char ****boss,
		char ****start, char *task_str)
{
	char	*end;

	end = ***boss;
	if (ft_strrchr_printf(task_str, '.'))
	{
		***boss = ft_strchr(***start, '.');
		if (****boss == '.' && (((***(*boss + 1)) == 's'
					|| (ft_strrchr_printf("dixXpu", ***(*boss + 1))
						&& ****to_print[0][0] == '0'))))
		{
			free(*****to_print);
			*****to_print = ft_strdup("");
			(***boss)++;
		}
	}
	return (end);
}

static void	ft_handle_precision(char ******to_print, char ****boss,
		char ****start, char **end)
{
	int	precision;

	if (ft_strrchr_printf(***boss, '.') && ft_chr_str_cmp(**end, "sdixXup"))
	{
		precision = ft_go_back_for_precision(&boss, &start);
		ft_apply_precision(&to_print, precision, *end, ***start);
		if (***boss != ***start)
			(***boss)--;
	}
}

static int	ft_go_back_for_precision(char *****boss, char *****start)
{
	int	precision;

	precision = 0;
	while (ft_isdigit(*****boss) && ****boss >= ****start)
	{
		if (****boss == ****start)
			break ;
		(****boss)--;
	}
	precision = ft_atoi_printf(****boss);
	return (precision);
}

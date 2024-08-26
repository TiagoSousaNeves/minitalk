/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_handle_space_and_zero.c						 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tfelguei <tfelguei.students.42porto.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/05/21 06:48:15 by tcosta-f		  #+#	#+#			 */
/*   Updated: 2024/05/24 16:36:38 by tfelguei		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_space_and_zero(char ****temp_print, char *start,
				char *boss, char *str_width);
static void	ft_handle_hex(char *****temp_print, char **temp, char *str_width,
				char end_char);

void	ft_handle_space_and_zero(char ****temp_print, char *start, char *boss,
		char *str_width)
{
	char	*temp;
	char	*end;

	temp = ft_strdup(***temp_print);
	free(***temp_print);
	end = ft_str_str_cmp(boss, "cspdiuxX", ft_strlen(boss));
	if ((*boss == '0' || *(boss + 1) == '0' || *start == ' ') && (*end == 'x'
			|| *end == 'X'))
	{
		if (*start == '#' && (*(boss + 1) == '0' || *(boss + 1) == '.')
			&& *str_width)
		{
			ft_handle_hex(&temp_print, &temp, str_width, *end);
			***temp_print = ft_strdup(temp);
			free(temp);
			return ;
		}
	}
	***temp_print = ft_strjoin(str_width, temp);
	free(temp);
	free(str_width);
}

static void	ft_handle_hex(char *****temp_print, char **temp, char *str_width,
		char end_char)
{
	char	**split_temp;
	char	*joined_temp;

	joined_temp = NULL;
	split_temp = ft_split_printf(*temp, end_char);
	if (end_char == 'X')
		joined_temp = ft_strjoin(split_temp[0], "X");
	else if (end_char == 'x')
		joined_temp = ft_strjoin(split_temp[0], "x");
	free(*temp);
	*temp = ft_strjoin(joined_temp, str_width);
	free(joined_temp);
	joined_temp = ft_strjoin(split_temp[0], split_temp[1]);
	free(split_temp[0]);
	free(split_temp[1]);
	****temp_print = joined_temp;
	free(*temp);
	free(str_width);
}

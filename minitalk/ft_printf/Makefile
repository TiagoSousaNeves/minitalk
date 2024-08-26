# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 19:02:38 by tcosta-f          #+#    #+#              #
#    Updated: 2024/08/07 04:22:09 by tcosta-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

FUNC = ft_printf.c ft_split_printf.c ft_itoa_printf.c ft_callocate_string.c
FUNC += ft_str_str_cmp.c ft_what_to_do.c ft_handle_specifier.c ft_calloc_printf.c
FUNC += ft_intlen.c ft_ptr_to_str.c ft_base_nb_len.c
FUNC += ft_chrstr.c ft_strndup.c ft_handle_space.c ft_handle_end_p_or_xs.c
FUNC += ft_n_char_in_str.c ft_ispositive.c ft_atoi_printf.c ft_bspace_printf.c 
FUNC += ft_count_words_printf.c ft_chr_str_cmp.c ft_uintlen.c ft_strnstr_printf.c
FUNC += ft_strrchr_printf.c ft_check_fill_width_organize_to_print.c
FUNC += ft_save_to_print_and_check_flag.c ft_check_what_to_do.c ft_bzero_printf.c
FUNC += ft_organize_to_print.c ft_handle_dot.c ft_handle_zero.c ft_apply_precision.c
FUNC += ft_handle_aux_negative.c ft_handle_space_and_zero.c ft_handle_plus.c
FUNC += ft_hexa_to_str.c ft_hexa_to_print.c ft_arg_to_str.c ft_unsigint_to_str.c 
FUNC += ft_handle_default_condition.c ft_handle_positive_plus_or_space.c ft_toupper.c
FUNC += ft_isdigit.c ft_memcpy.c ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c 
FUNC += ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_strtrim.c ft_substr.c 

OBJS = ${FUNC:.c=.o}

RM = @rm -fr
CC = @gcc
MK_LIB = @ar rcs
CFLAGS = -Werror -Wextra -Wall

all: $(NAME)

bonus: all

$(NAME): $(OBJS)  
	$(MK_LIB) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus

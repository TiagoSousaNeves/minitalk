# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 17:12:50 by tcosta-f          #+#    #+#              #
#    Updated: 2024/08/26 23:26:43 by tcosta-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/ft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Build all binaries
all: $(NAME_CLIENT) $(NAME_SERVER)

# Build all binaries and bonus programs
bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

# Build client
$(NAME_CLIENT): $(FT_PRINTF_LIB) $(SRC_CLIENT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(FT_PRINTF_LIB) -o $(NAME_CLIENT)

# Build server
$(NAME_SERVER): $(FT_PRINTF_LIB) $(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(FT_PRINTF_LIB) -o $(NAME_SERVER)

# Build bonus client
$(NAME_CLIENT_BONUS): $(FT_PRINTF_LIB) $(SRC_CLIENT_BONUS) minitalk_bonus.h
	$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) $(FT_PRINTF_LIB) -o $(NAME_CLIENT_BONUS)

# Build bonus server
$(NAME_SERVER_BONUS): $(FT_PRINTF_LIB) $(SRC_SERVER_BONUS) minitalk_bonus.h
	$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) $(FT_PRINTF_LIB) -o $(NAME_SERVER_BONUS)

# Build ft_printf library
$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Clean object files and binaries
clean:
	@rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

# Remove object files, binaries, and ft_printf library
fclean: clean
	@rm -f $(FT_PRINTF_LIB)

# Remove object files, binaries, and ft_printf library, then rebuild everything
re: fclean all

.PHONY: all clean fclean re bonus

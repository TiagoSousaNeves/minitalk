# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 17:12:50 by tcosta-f          #+#    #+#              #
#    Updated: 2024/09/02 01:39:04 by tcosta-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c
FT_PRINTF_DIR = ../ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/ft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Build all bonus binaries
all: $(NAME_CLIENT) $(NAME_SERVER)
	@echo "Moving bonus executables to main folder..."; \
	cp $(NAME_CLIENT) ../$(NAME_CLIENT); \
	cp $(NAME_SERVER) ../$(NAME_SERVER)

# Build bonus client
$(NAME_CLIENT): $(SRC_CLIENT_BONUS) $(FT_PRINTF_LIB)
	@echo "Building bonus client..."; \
	$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) $(FT_PRINTF_LIB) -o $(NAME_CLIENT)

# Build bonus server
$(NAME_SERVER): $(SRC_SERVER_BONUS) $(FT_PRINTF_LIB)
	@echo "Building bonus server..."; \
	$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) $(FT_PRINTF_LIB) -o $(NAME_SERVER)

# Build ft_printf library
$(FT_PRINTF_LIB):
	@echo "Building ft_printf library..."; \
	$(MAKE) -C $(FT_PRINTF_DIR)

# Clean object files and binaries
clean:
	@echo "Cleaning bonus binaries...";
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)

# Remove object files, binaries, and ft_printf library
fclean: clean
	@echo "Removing ft_printf library...";
	@rm -f $(FT_PRINTF_LIB)

# Remove object files, binaries, and ft_printf library, then rebuild everything
re: fclean all

.PHONY: all clean fclean re

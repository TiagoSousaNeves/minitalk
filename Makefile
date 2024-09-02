# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 17:12:50 by tcosta-f          #+#    #+#              #
#    Updated: 2024/09/02 01:42:05 by tcosta-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
SRC_CLIENT = client.c
SRC_SERVER = server.c
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/ft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Build all mandatory binaries
all: $(NAME_CLIENT) $(NAME_SERVER)

# Build client
$(NAME_CLIENT): $(SRC_CLIENT) $(FT_PRINTF_LIB)
	@echo "Building mandatory client..."; \
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(FT_PRINTF_LIB) -o $(NAME_CLIENT)

# Build server
$(NAME_SERVER): $(SRC_SERVER) $(FT_PRINTF_LIB)
	@echo "Building mandatory server..."; \
	$(CC) $(CFLAGS) $(SRC_SERVER) $(FT_PRINTF_LIB) -o $(NAME_SERVER)

# Build bonus binaries by invoking the Makefile in the bonus directory
bonus:
	@echo "Building bonus version..."; \
	$(MAKE) -C bonus

# Build ft_printf library
$(FT_PRINTF_LIB):
	@echo "Building ft_printf library..."; \
	$(MAKE) -C $(FT_PRINTF_DIR)

# Clean object files and binaries
clean:
	@echo "Cleaning binaries...";
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C bonus clean


# Remove object files, binaries, and ft_printf library
fclean: clean
	@echo "Removing ft_printf library...";
	@rm -f $(FT_PRINTF_LIB)

# Remove object files, binaries, and ft_printf library, then rebuild everything
re: fclean all

.PHONY: all clean fclean re bonus

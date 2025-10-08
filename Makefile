# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 16:42:17 by lyvan-de          #+#    #+#              #
#    Updated: 2025/10/08 13:34:35 by lyvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
BUILD_DIR = ./build
SRC = main.c 

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
INCLUDE = -I $(LIBFT_PATH) -I $(LIBMLX_PATH)/include
LIBFT_PATH =./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBMLX = ./MLX42
LIBMLX_LINK := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
CFLAGS = -Wall -Werror -Wextra -g
CC = cc

all : libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	
$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $^ $(LIBFT) $(LIBMLX_LINK) -o $@ -lm -lglfw 
# flags for compiling MLX42 on mac at home: -framework Cocoa -framework OpenGL -framework IOKit

$(BUILD_DIR)/%.o : %.c
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all

clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY: all clean fclean re libmlx

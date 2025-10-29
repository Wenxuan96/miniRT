# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 16:42:17 by lyvan-de          #+#    #+#              #
#    Updated: 2025/11/01 19:38:35 by wxi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
BUILD_DIR = ./build
SRC = main.c graphics.c create_data.c vector.c vector2.c viewport.c ray.c render.c

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBMLX = ./MLX42
LIBMLX_PATH = ./MLX42
INCLUDE = -I $(LIBFT_PATH) -I $(LIBMLX_PATH)/include
LIBMLX_LINK := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
CFLAGS = -Wall -Werror -Wextra -g
CC = cc
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
else
	FRAMEWORKS =
endif

all : libmlx $(NAME) 

mac : MACFLAGS += -framework Cocoa -framework OpenGL -framework IOKit
mac : all

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	
$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $^ $(LIBFT) $(LIBMLX_LINK) -o $@ $(FRAMEWORKS)

# On macOS we need the Cocoa/OpenGL/IOKit frameworks; on Linux these flags must be empty
# Also avoid -shared here (we want an executable). The MLX42 static lib and extra libs
# are included via $(LIBMLX_LINK).

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

.PHONY: all clean fclean re libmlx mac

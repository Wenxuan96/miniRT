# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2025/12/28 18:30:26 by wxi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
BUILD_DIR = ./build
SRC = main.c input_data.c vec_utils1.c vec_utils2.c viewport.c ray.c render.c test.c
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBMLX_PATH = ./MLX42
INCLUDE = -I $(LIBFT_PATH) -I $(LIBMLX_PATH)/include
LIBMLX_LINK := $(LIBMLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm
CFLAGS = -Wall -Werror -Wextra -g
CC = cc

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
    BREW_PREFIX = $(shell brew --prefix 2>/dev/null || echo /opt/homebrew)
    LIBMLX_LINK := $(LIBMLX_PATH)/build/libmlx42.a -ldl -L$(BREW_PREFIX)/lib -lglfw -pthread -lm
else
    FRAMEWORKS =
    LIBMLX_LINK := $(LIBMLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm
endif

all : libmlx $(NAME)

# mac target for convenience: append mac frameworks and build
mac : FRAMEWORKS += -framework Cocoa -framework OpenGL -framework IOKit
mac : all

libmlx:
	@cmake $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && make -C $(LIBMLX_PATH)/build -j4
	
$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LIBMLX_LINK) -o $@ $(FRAMEWORKS)

$(BUILD_DIR)/%.o : %.c
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all

clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(LIBMLX_PATH)/build

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY: all clean fclean re libmlx mac
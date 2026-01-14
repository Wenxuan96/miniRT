# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2026/01/14 13:33:25 by lyvan-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = miniRT
BUILD_DIR = ./build
SRC = src/parsing/parse_file.c src/parsing/parse_objects.c src/parsing/parse_scene_setup.c src/parsing/parse_tuple.c src/parsing/parse_utils.c src/parsing/parsing.c src/parsing/scene.c \
	src/vectors/vec_utils1.c src/vectors/vec_utils2.c src/matrices/matrices.c src/matrices/mat_invert.c src/matrices/transformation.c src/matrices/ray_sphere.c \
	src/miniRT.c src/objects/ray.c src/objects/viewport.c 
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
LIBFT_PATH = src/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBMLX_PATH = MLX42
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
	mkdir -p $(dir $@)
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
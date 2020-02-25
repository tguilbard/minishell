# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 09:02:30 by ldutriez          #+#    #+#              #
#    Updated: 2019/12/03 08:36:17 by ldutriez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libLGL.a

CC =		gcc

MLX_DIR = 	$(shell find lib/mlx -type d)
SRC_DIR = 	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d) $(shell find lib/mlx -type d)
LIB_DIR =
OBJ_DIR = 	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):) $(foreach dir, $(MLX_DIR), $(dir):)
vpath %.m $(foreach dir, $(MLX_DIR), $(dir):)


# List de toute les library a linker au projet (le nom - le lib et - le .a)
FRAMEWORK = OpenGL AppKit
LIB =

#SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file)))) mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_mouse.m
MLX_SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c \
		mlx_int_str_to_wordtab.c mlx_png.c mlx_mouse.m

SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

OBJ1 = $(MLX_SRC:%.c=%.o)
OBJ2 = $(OBJ1:%.m=%.o)
MLX_OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ2))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

#Compilation flag
CFLAGS = #-Wall -Wextra -Werror -fsanitize=address

IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir))

LFLAGS = $(foreach dir, $(LIB_DIR), -L $(dir) ) $(foreach lib, $(LIB), -l $(lib) ) $(foreach framework, $(FRAMEWORK), -framework $(framework) )

# Colors

_GREY=	$'\x1b[30m
_RED=	$'\x1b[31m
_GREEN=	$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=	$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=	$'\x1b[36m
_WHITE=	$'\x1b[37m

all:
				@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
				@make $(NAME)

show:
				@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
				@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"

$(OBJ_DIR)/%.o : %.c
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(OBJ_DIR)/%.o : %.m
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(NAME): 		$(MLX_OBJ) $(OBJ) Makefile
				@echo "-----\nCreating library $(_YELLOW)$@$(_WHITE) ... \c"
				@ar -rc $(NAME) $(OBJ) $(MLX_OBJ)
				@ranlib $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

debug:			$(MLX_OBJ) $(OBJ) $(NAME) main.c
				@echo "Creating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
				@$(CC) $(CFLAGS) $(IFLAGS) main.c -o debug $(LFLAGS) -L . -l LGL
				@echo "$(_GREEN)DONE$(_WHITE)\n"
				@echo "Execution !\n-----"
				@./debug

norme:
				norminette $(SRC_DIR)

re:				fclean all

mlx_clean:
				@echo "$(_WHITE)Deleting MLX Objects $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
				@$(foreach file, $(MLX_OBJ), rm -rf $(file))
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"
clean:
				@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
				@$(foreach file, $(OBJ), rm -rf $(file))
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
				@rm -f $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all clean flcean re show exec norme

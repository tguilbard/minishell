# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 08:17:15 by ldutriez          #+#    #+#              #
#    Updated: 2020/03/12 11:54:54 by tguilbar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
#BONUS_NAME	=

CC =		gcc

SRC_DIR = 	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d) \
			$(shell find libs/libft/includes -type d)
LIB_DIR =	libs/libft
OBJ_DIR = 	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# List de toute les library a linker au projet (le nom - le lib et - le .a)
LIB = ft
#FRAMEWORK = OpenGL Appkit

SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

#NORMAL_SRC = 

#BONUS_SRC =

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
NORMAL_OBJ = $(OBJ) #$(addprefix $(OBJ_DIR)/, $(NORMAL_SRC:%.c=%.o))
#BONUS_OBJ = $(OBJ) $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:%.c=%.o))

#Compilation flag
CFLAGS = -Wall -Wextra -fsanitize=address -g3 -O3 #-Werror

IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir))

LFLAGS =	$(foreach dir, $(LIB_DIR), -L $(dir)) \
			$(foreach lib, $(LIB), -l $(lib)) \
#			$(foreach frame, $(FRAMEWORK), -framework  $(frame))

# Colors

_GREY=	$'\x1b[30m
_RED=	$'\x1b[31m
_GREEN=	$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=	$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=	$'\x1b[36m
_WHITE=	$'\x1b[37m

all:			$(NAME)

show:
				@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
				@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LIB_DIR:\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
				@echo "$(_BLUE)LIB_INC :\n$(_YELLOW)$(LIB_INC)$(_WHITE)"
				@echo "$(_BLUE)INC_DIR :\n$(_YELLOW)$(INC_DIR)$(_WHITE)"

install:
				@$(foreach dir, $(LIB_DIR), make -C $(dir) ; )

re-install:
				@$(foreach dir, $(LIB_DIR), make -C $(dir) re ; )

uninstall:
				@$(foreach dir, $(LIB_DIR), make -C $(dir) fclean ; )

$(OBJ_DIR)/%.o : %.c
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"


$(NAME): 		$(INC_DIR) $(NORMAL_OBJ) Makefile
				@echo "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... \c"
				@$(CC) $(CFLAGS) $(LFLAGS) $(NORMAL_OBJ) -o $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

#bonus:			$(BONUS_NAME)

#$(BONUS_NAME):	$(INC_DIR) $(BONUS_OBJ) Makefile
#				@echo "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... \c"
#				@$(CC) $(CFLAGS) $(LFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)
#				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

norme:
				norminette $(SRC_DIR)

re:				fclean all

clean:
				@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
				@rm -rf $(OBJ_DIR)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
				@rm -f $(NAME) $(BONUS_NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all clean flcean re install re-install show norme uninstall #bonus

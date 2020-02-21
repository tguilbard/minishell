# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 14:24:36 by ldutriez          #+#    #+#              #
#    Updated: 2020/02/17 14:21:17 by tguilbar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a

ASM			= nasm
ASMFLAGS	= -f macho64 -g
SRC_DIR = 	$(shell find srcs -type d)
SRC 		= $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.s), $(notdir $(file))))
OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:%.s=%.o))
INC_DIR		= $(shell find includes -type d)
TEST_BINARY	= test
TEST_FILES	= main.c
TEST_CC		= gcc
TEST_CFLAGS	= -Wall -Wextra -Werror #-O3 -fsanitize=address -g3

vpath %.s $(foreach dir, $(SRC_DIR), $(dir):)

# Colors

_GREY=	$'\x1b[30m
_RED=	$'\x1b[31m
_GREEN=	$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=	$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=	$'\x1b[36m
_WHITE=	$'\x1b[37m

all				: $(NAME)

show:
				@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
				@echo "$(_BLUE)INC_DIR :\n$(_YELLOW)$(INC_DIR)$(_WHITE)"

$(OBJ_DIR)/%.o: %.s
			@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
			@mkdir -p $(OBJ_DIR)
			@$(ASM) $(ASMFLAGS) -o $@ $<
			@echo "$(_GREEN)DONE$(_WHITE)"

$(NAME)			: $(OBJ)
			@echo "-----\nCreating Library $(_YELLOW)$@$(_WHITE) ... \c"
			@ar -rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "$(_GREEN)DONE$(_WHITE)\n-----"


$(TEST_BINARY)	: $(NAME) $(TEST_FILES)
			@echo "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... \c"
			@$(TEST_CC) $(TEST_CFLAGS) $(TEST_FILES) -I $(INC_DIR) $(NAME) -o $(TEST_BINARY)
			@echo "$(_GREEN)DONE$(_WHITE)\n-----"

clean			:
			@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
			@rm -f $(OBJ)
			@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean			: clean
			@echo "Deleting Library File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
			@rm -f $(NAME)
			@echo "$(_GREEN)DONE$(_WHITE)\n-----"

re				: fclean all

.PHONY			: all re clean fclean show

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 11:48:55 by seciurte          #+#    #+#              #
#    Updated: 2021/11/29 16:52:02 by seciurte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	=   pipex

CC          	=   clang

SRC_DIR			= 	$(shell find srcs -type d)
INC_DIR			= 	$(shell find includes -type d) \
					$(shell find libs/libft -type d) \
					$(shell find libs/gnl -type d)
LIB_DIR			=	libs/libft libs/gnl
OBJ_DIR			=	.objs
LIB				=	libs/libft/libft.a libs/gnl/gnl.a

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

BUILD			=	$(CC) $(CFLAGS) ${IFLAGS} $(OBJ) $(LFLAGS) $(LIB) -o $(NAME)
BUILD_BNS		=	$(CC) $(CFLAGS) ${IFLAGS} $(OBJ_BONUS) $(LFLAGS) $(LIB) -o $(NAME)

# library -----------------------------------------------------------

SRC			= 	error_handling_pipex.c \
				free_struct.c\
				parsing_pipex.c parsing_pipex2.c\
				pipex.c

SRC_BNS		=	$(addsuffix _bonus.c, $(basename $(SRC)))\
				here_doc_bonus.c

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR)/, $(SRC_BNS:%.c=%.o))

# Compilation flags -------------------------------------------------

D_NO_BONUS  =	-DBONUS=0

D_BONUS		=	-DBONUS=1

CFLAGS		=	-Wall -Wextra -Werror

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir))

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

# Colors ------------------------------------------------------------

_NOCOLOR=\033[0m
_RED=\033[0;31m
_GREEN=\033[0;32m
_ORANGE=\033[0;33m
_BLUE=\033[0;34m
_PURPLE=\033[0;35m
_CYAN=\033[0;36m
_LIGHTGRAY=\033[0;37m
_DARKGRAY=\033[1;30m
_LIGHTRED=\033[1;31m
_LIGHTGREEN=\033[1;32m
_YELLOW=\033[1;33m
_LIGHTBLUE=\033[1;34m
_LIGHTPURPLE=\033[1;35m
_LIGHTCYAN=\033[1;36m
_WHITE=\033[1;37m

# main part ---------------------------------------------------------

all:
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make BONUS=$(D_NO_BONUS) $(NAME)

bonus: fclean $(OBJ_BONUS)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@${BUILD_BNS}
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

show:
	@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
	@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LIB_DIR :\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)$(_WHITE)"

install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir);)

re-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) re;)

fclean-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) fclean;)

$(NAME): install $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@${BUILD}
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(BONUS) $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

re:	fclean all

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@rm -rf .objs
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all bonus show install re-install re clean flcean

#Credit to @gozsertt
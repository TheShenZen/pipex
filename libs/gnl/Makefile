# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 14:49:36 by seciurte          #+#    #+#              #
#    Updated: 2021/03/15 16:49:02 by seciurte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	get_next_line.c\
			get_next_line_utils.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	+=	-Wall -Wextra -Werror

NAME	=	gnl.a

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
		ar -rcs ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
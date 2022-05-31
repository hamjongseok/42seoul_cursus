# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 19:20:27 by hamjongseog       #+#    #+#              #
#    Updated: 2022/05/31 19:24:35 by hamjongseog      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAG = -Wall -Werror -Wextra
RM = rm -f
AR = ar 
ARFLAGS = crs
INCS = inc/so_long.h

SRCS = srcs/main.c

OBJS =	${SRCS:.c=.o}


all : ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${RMFLAG} ${OBJS} 

fclean:	clean
		${RM} ${RMFLAG} ${NAME}

re:	fclean all

$(NAME): ${OBJS}
		   $(CC) $(CFLAGS) $(SRCS) -o $(NAME)

.PHONY : all clean fclean re


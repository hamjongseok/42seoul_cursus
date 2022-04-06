# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 17:41:07 by hamjongseog       #+#    #+#              #
#    Updated: 2022/04/06 17:43:52 by hamjongseog      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc
CFLAG = -Wall -Werror -Wextra
RM = rm -f
AR = ar 
ARFLAGS = crs
INCS = ./ft_printf.h

SRCS =	srcs/main.c \
		

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
		${AR} ${ARFLAGS} $@ $^

.PHONY : all clean fclean re

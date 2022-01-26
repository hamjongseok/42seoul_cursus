# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 15:06:20 by hamjongseog       #+#    #+#              #
#    Updated: 2022/01/26 11:49:54 by hamjongseog      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAG = -Wall -Werror -Wextra
RM = rm -f
AR = ar 
ARFLAGS = crs
INCS = ./ft_printf.h

SRCS =	./ft_printf.c \
		ft_print_di.c \
		ft_print_u.c  \
		ft_print_x.c  \
		ft_print_xx.c \
		ft_print_p.c
	

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

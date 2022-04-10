# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 17:41:07 by hamjongseog       #+#    #+#              #
#    Updated: 2022/04/08 15:05:26 by hamjongseog      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc
CFLAG = -Wall -Werror -Wextra
RM = rm -f
AR = ar 
ARFLAGS = crs
INCS = inc/push_swap.h

SRCS =	srcs/main.c \
		srcs/ft_input.c \
		srcs/ft_init.c \
		srcs/utility.c \
		srcs/ft_split.c
		
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

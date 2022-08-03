# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jham <jham@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 17:41:07 by jham              #+#    #+#              #
#    Updated: 2022/05/14 14:29:48 by jham             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc
CFLAG = -Wall -Werror -Wextra
RM = rm -f
AR = ar 
ARFLAGS = crs
INCS = inc/push_swap.h

SRCS =	srcs/main.c \
		srcs/ft_input.c \
		srcs/ft_init.c \
		srcs/utility.c \
		srcs/ft_split.c \
		srcs/ft_stack.c \
		srcs/ft_list.c \
		function/ft_swap.c \
		function/ft_rotate.c \
		function/ft_rrotate.c \
		function/ft_push.c \
		sort/ft_sort_two.c \
		sort/ft_sort_five.c \
		sort/ft_sort_three.c \
		sort/ft_sort_utils.c \
		sort/ft_sort_more.c
		
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

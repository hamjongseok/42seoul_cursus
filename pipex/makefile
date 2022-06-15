# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:33:05 by hamjongseog       #+#    #+#              #
#    Updated: 2022/06/15 15:33:32 by hamjongseog      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

D_UTILES	=	utiles/
SRCS		=	pipex.c \
				$(D_UTILES)exit_perror.c 

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		gcc -o $(NAME) $(OBJS)

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@

clean		:
		rm -f $(OBJS)

fclean		:	clean
		rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus

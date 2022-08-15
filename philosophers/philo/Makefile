# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 01:42:12 by hamjongseog       #+#    #+#              #
#    Updated: 2022/08/15 01:45:48 by hamjongseog      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	philo

SRCS		=	main.c \
					action.c \
					init.c \
					utils.c

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		cc -o $(NAME) $(OBJS)

%.o			:	%.c
		cc $(FLAGS) -c $^ -I./ -o $@

clean		:
		rm -f $(OBJS)

fclean		:	clean
		rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus

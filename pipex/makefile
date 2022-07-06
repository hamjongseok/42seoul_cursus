# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:33:05 by hamjongseog       #+#    #+#              #
#    Updated: 2022/07/06 13:23:36 by hamjongseog      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

D_UTILES	=	utiles/
SRCS		=	pipex.c \
				$(D_UTILES)exit_perror.c \
				$(D_UTILES)strnstr.c \
				$(D_UTILES)ft_strncmp.c \
				$(D_UTILES)ft_split.c \
				$(D_UTILES)ft_calloc.c \
				$(D_UTILES)ft_strlcpy.c \
				$(D_UTILES)ft_strjoin.c \
				$(D_UTILES)ft_strdup.c \
				$(D_UTILES)ft_strlen.c


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

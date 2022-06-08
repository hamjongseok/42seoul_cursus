# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 19:20:27 by hamjongseog       #+#    #+#              #
#    Updated: 2022/06/08 12:13:57 by hamjongseog      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -g
CFLAG = -Wall -Werror -Wextra
RM = rm -f
AR = ar 
ARFLAGS = crs
INCS = inc/so_long.h

SRCS_NAME = main.c \
			images.c \
			get_next_line.c \
			get_next_line_utils.c \
			map.c \
			utils.c

SRCS_PATH = ./srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

LIB_NAME = ft
LIB_PATH = ./libft

MLX_NAME = mlx
MLX_PATH = ./mlx

$(NAME) : $(OBJS)
		$(MAKE) -C $(LIB_PATH) all
		$(MAKE) -C $(MLX_PATH)
		$(CC) $(CFLAGS) \
		-L$(LIB_PATH) -l$(LIB_NAME) \
		-L$(MLX_PATH) -l$(MLX_NAME) \
		-framework OpenGL -framework Appkit -lz $^ -o $@

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -I$(INC_PATH) -I$(MLX_PATH) -I$(LIB_PATH) -c $< -o $@

all : ${NAME}

clean:
	${RM} ${RMFLAG} ${OBJS} 

fclean:	clean
		${RM} ${RMFLAG} ${NAME}

re:	fclean all

.PHONY : all clean fclean re


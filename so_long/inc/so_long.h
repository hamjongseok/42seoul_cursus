/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:47:01 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/07 18:33:03 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../mlx/mlx.h"
#include "unistd.h"
#include "../libft/libft.h"
#include "../srcs/get_next_line.h"
#include <fcntl.h>

#define X_EVENT_KEY_PRESS 2   // mlx_hook 함수의 두번째 인자
#define X_EVENT_KEY_RELEASE 3 // x_event에 들어가는 값

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53 // MAC OS의 키보드 코드 들이다.

typedef struct s_img
{
    void *chara;
    void *chest;
    void *land;
    void *rune;
    void *rune2;
    void *wall;
} t_img;

typedef struct s_game
{
    void *mlx;
    void *win;
    t_img img;
    int wid;
    int hei;
    char *str_line;
    int all_col;
    int col_cnt;
    int walk_cnt;
} t_game;

/*
images.c
*/
t_img img_init(void *mlx);
void map_read(char *filename, t_game *game);
void print_err(char *message);

#endif

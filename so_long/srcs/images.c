/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:16:21 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/09 19:45:39 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_img img_init(void *mlx)
{
    t_img gm;
    int wid;
    int hei;

    gm.land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &wid, &hei);
    gm.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wid, &hei);
    gm.player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &wid, &hei);
    gm.item = mlx_xpm_file_to_image(mlx, "./images/item.xpm", &wid, &hei);
    gm.exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &wid, &hei);
    gm.o_exit = mlx_xpm_file_to_image(mlx, "./images/o_exit.xpm", &wid, &hei);
    return (gm);
}

void put_img(t_game *g, int w, int h)
{
    if (g->str_line[h * g->wid + w] == '1')
    {
        mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 64, h * 64);
    }
    else if (g->str_line[h * g->wid + w] == 'C')
        mlx_put_image_to_window(g->mlx, g->win, g->img.item, w * 64, h * 64);
    else if (g->str_line[h * g->wid + w] == 'P')
    {
        mlx_put_image_to_window(g->mlx, g->win, g->img.player, w * 64, h * 64);
    }
    else if (g->str_line[h * g->wid + w] == 'E' && g->all_col == g->col_cnt)
    {
        mlx_put_image_to_window(g->mlx, g->win, g->img.o_exit, w * 64, h * 64);
    }
    else if (g->str_line[h * g->wid + w] == 'E')
    {
        mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * 64, h * 64);
    }
    else
    {
        mlx_put_image_to_window(g->mlx, g->win, g->img.land, w * 64, h * 64);
    }
}

void setting_img(t_game *game)
{
    int hei;
    int wid;

    hei = 0;
    while (hei < game->hei) // 0< 5
    {
        wid = 0;
        while (wid < game->wid) // 0 < 13  하나씩 찍는거지
        {
            put_img(game, wid, hei);
            wid++;
        }
        hei++;
    }
}
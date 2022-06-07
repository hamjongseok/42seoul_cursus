/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:16:21 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/07 17:48:01 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_img img_init(void *mlx)
{
    t_img rt;
    int wid;
    int hei;

    rt.land = mlx_xpm_file_to_image(mlx, "../images/road.xpm", &wid, &hei);
    rt.wall = mlx_xpm_file_to_image(mlx, "../images/wall.xpm", &wid, &hei);
    return (rt);
}
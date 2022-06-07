/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:18:40 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/07 18:33:21 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>

void print_err(char *message)
{
	write(2, "Error\n", 6);				   //표준에러 , 에러출력
	write(2, message, ft_strlen(message)); //표준에러, 메세지 출력
	exit(1);
}

void game_init(t_game *g, char *map)
{
	g->mlx = mlx_init();	   //디스플레이 연결 함수
	g->img = img_init(g->mlx); //이미지 연결시키기
	map_read(map, g);
}

int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2) //예외처리
		print_err("Map is missing.\n");
	game = malloc(sizeof(t_game));
	game_init(game, argv[1]);
	return (0);
}

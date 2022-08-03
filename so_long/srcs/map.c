/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:51:25 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/10 00:08:50 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_read_one(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		print_err("파일 읽기에 실패했습니다. \n");
	line = get_next_line(fd);
	game->hei = 0;
	game->walk = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup_x_newline(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line)
		{
			game->str_line = ft_strjoin_x_newline(game->str_line, line);
		}
	}
	close(fd);
}

void	map_check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->str_line))
	{
		if (i < game->wid)
		{
			if (game->str_line[i] != '1')
				print_err("맵은 벽으로 둘러싸야 합니다. \n");
		}
		else if (i % game->wid == 0 || i % game->wid == game->wid - 1)
		{
			if (game->str_line[i] != '1')
				print_err("맵은 벽으로 둘러싸야 합니다. \n");
		}
		else if (i > ft_strlen(game->str_line) - game->wid)
		{
			if (game->str_line[i] != '1')
				print_err("맵은 벽으로 둘러싸야 합니다. \n");
		}
		i++;
	}
}

void	map_check_param(t_game *game)
{
	int	i;
	int	num_e;
	int	num_p;

	i = 0;
	num_e = 0;
	num_p = 0;
	game->c_total = 0;
	game->c_cnt = 0;
	while (i++ < ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'E')
			num_e++;
		else if (game->str_line[i] == 'P')
			num_p++;
		else if (game->str_line[i] == 'C')
			game->c_total++;
	}
	if (num_e == 0)
		print_err("맵은 하나의 출구가 있어야 합니다. \n");
	if (game->c_total == 0)
		print_err("맵에는 하나이상의 수집품이 있어야합니다\n");
	if (num_p != 1)
		print_err("맵에는 하나의 플레이어가 존재해야합니다.\n");
}

void	map_check(t_game *game)
{
	if (game->hei * game->wid != ft_strlen(game->str_line))
		print_err("맵은 직사각형이여야 합니다. \n");
	map_check_wall(game);
	map_check_param(game);
}

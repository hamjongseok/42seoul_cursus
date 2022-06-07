/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:51:25 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/07 18:35:47 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void map_read(char *filename, t_game *game)
{
    int fd;
    char *line;

    fd = open(filename, O_RDONLY); //파일 디스크립터의 정수 할당 , 읽기전용
    if (fd <= 0)
        print_err("File open fail. \n");
    line = get_next_line(fd);
    game->hei = 0;
    game->walk_cnt = 0;
    game->wid = ft_strlen(line) - 1; //왜 -1 하는거지?
    game->str_line = ft_strdup_without_newline(line);
}
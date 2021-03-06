/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:51:25 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/09 23:58:00 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void map_read_one(char *file, t_game *game)
{
    int fd;
    char *line;

    fd = open(file, O_RDONLY); //파일 디스크립터의 정수 할당 , 읽기전용
    if (fd <= 0)
        print_err("파일 읽기에 실패했습니다. \n");
    line = get_next_line(fd); //첫번째 줄 들어감
    game->hei = 0;
    game->walk = 0;                             //움직인횟수 0으로 초기화
    game->wid = ft_strlen(line) - 1;            //-해야 딱맞다
    game->str_line = ft_strdup_x_newline(line); //line, 즉 첫번째 줄의 문자하나씩 다 넣어줌
    free(line);
    while (line)
    {
        game->hei++;
        line = get_next_line(fd); //라인을 여기서 읽기때문에 hei값이 맞게 들어온다.
        if (line)
        {
            game->str_line = ft_strjoin_x_newline(game->str_line, line);
        }
    } //최종적으로 str_line에 맵인자가 쭈우우욱 이어져있다.
    close(fd);
}

void map_check_wall(t_game *game)
{
    int i;

    i = 0;
    while (i < ft_strlen(game->str_line)) //65
    {
        if (i < game->wid) //13, wid보다 작다면 벽을 검사할수있다.
        {
            if (game->str_line[i] != '1') //첫번째줄은 무조건 1이여야한다.
                print_err("맵은 벽으로 둘러싸야 합니다. \n");
        }
        else if (i % game->wid == 0 || i % game->wid == game->wid - 1) //첫글자, 마지막 글자
        {
            if (game->str_line[i] != '1')
                print_err("맵은 벽으로 둘러싸야 합니다. \n");
        }
        else if (i > ft_strlen(game->str_line) - game->wid) //마지막 줄 검사
        {
            if (game->str_line[i] != '1')
                print_err("맵은 벽으로 둘러싸야 합니다. \n");
        }
        i++;
    }
}

void map_check_param(t_game *game) //맵의 인자들을 검사해준다
{
    int i;
    int num_e;
    int num_p;

    i = 0;
    num_e = 0;                              //exit
    num_p = 0;                              //player
    game->c_total = 0;                      //item
    game->c_cnt = 0;                        //item카운트
    while (i++ < ft_strlen(game->str_line)) //처음부터 끝까지 검사
    {
        if (game->str_line[i] == 'E') //E라면 ++
            num_e++;
        else if (game->str_line[i] == 'P') //P라면 ++;
            num_p++;
        else if (game->str_line[i] == 'C') //C의 총개수를 ++해줌
            game->all_col++;
    }
    if (num_e == 0)
        print_err("Map must have at least one exit. \n");
    if (game->all_col == 0)
        print_err("Map must have at least one collectible\n");
    if (num_p != 1) //P는 딱 하나만 존재해야한다.
        print_err("Map must have one starting position\n");
}

void map_check(t_game *game)
{
    if (game->hei * game->wid != ft_strlen(game->str_line)) //직사각형이여야 하기때문에
        print_err("맵은 직사각형이여야 합니다. \n");
    map_check_wall(game);  //벽 체크 함수
    map_check_param(game); //인자 검사해줌
}

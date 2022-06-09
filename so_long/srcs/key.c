/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:56:21 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/09 19:55:09 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int clear_game(t_game *game)
{
    game->walk++;
    printf("%s %d %s\n", "Congratulations ! you have", game->walk, "step.");
    exit(0);
}

void move_w(t_game *g)
{
    int i;

    i = 0;
    while (i++ < ft_strlen(g->str_line)) //0 < 65
    {
        if (g->str_line[i] == 'P') //P를 찾으면 빠져나옴
            break;
    }
    if (g->str_line[i - g->wid] == 'C') // 위로 올라갔는데 C라면 ++해줌
        g->col_cnt++;
    if (g->str_line[i - g->wid] == 'E' && g->all_col == g->col_cnt) //똑같다면 게임종료
        clear_game(g);
    else if (g->str_line[i - g->wid] != '1' && g->str_line[i - g->wid] != 'E')
    {
        g->str_line[i] = '0';          //P있던자리에 0을 넣고
        g->str_line[i - g->wid] = 'P'; //위에 자리에 P를 넣어줌
        g->walk++;
        printf("%d\n", g->walk);
        setting_img(g);
    }
}

void move_a(t_game *g) //왼쪽으로 한번
{
    int i;

    i = 0;
    while (i++ < ft_strlen(g->str_line))
    {
        if (g->str_line[i] == 'P')
            break;
    }
    if (g->str_line[i - 1] == 'C')
        g->col_cnt++;
    if (g->str_line[i - 1] == 'E' && g->all_col == g->col_cnt)
        clear_game(g);
    else if (g->str_line[i - 1] != '1' && g->str_line[i - 1] != 'E') //-1해야 왼쪽으로
    {
        g->str_line[i] = '0';
        g->str_line[i - 1] = 'P';
        g->walk++;
        printf("%d\n", g->walk);
        setting_img(g);
    }
}

void move_s(t_game *g) //밑으로는 + wid값
{
    int i;

    i = 0;
    while (i++ < ft_strlen(g->str_line))
    {
        if (g->str_line[i] == 'P')
            break;
    }
    if (g->str_line[i + g->wid] == 'C')
        g->col_cnt++;
    if (g->str_line[i + g->wid] == 'E' && g->all_col == g->col_cnt)
        clear_game(g);
    else if (g->str_line[i + g->wid] != '1' && g->str_line[i + g->wid] != 'E')
    {
        g->str_line[i] = '0';
        g->str_line[i + g->wid] = 'P';
        g->walk++;
        printf("%d\n", g->walk);
        setting_img(g);
    }
}

void move_d(t_game *g)
{
    int i;

    i = 0;
    while (i++ < ft_strlen(g->str_line))
    {
        if (g->str_line[i] == 'P')
            break;
    }
    if (g->str_line[i + 1] == 'C')
        g->col_cnt++;
    if (g->str_line[i + 1] == 'E' && g->all_col == g->col_cnt)
        clear_game(g);
    else if (g->str_line[i + 1] != '1' && g->str_line[i + 1] != 'E')
    {
        g->str_line[i] = '0';
        g->str_line[i + 1] = 'P';
        g->walk++;
        printf("%d\n", g->walk);
        setting_img(g);
    }
}
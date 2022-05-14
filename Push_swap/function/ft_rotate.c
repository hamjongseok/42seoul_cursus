/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:19:32 by jham              #+#    #+#             */
/*   Updated: 2022/05/14 15:02:25 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ra(t_stack *a, int *ra_cnt) //매개변수의미? a의 모든 원소를 1씩 위로 이동, 첫번째원소는 마지막원소가 된다.
{
    int adata;

    if (a->next == NULL) //예외처리
        return;
    adata = a->next->data; //7이들어감 첫번째 노드의 값 , 왜지 ?
    ft_pop(a);             //pop조짐
    ft_push_last(a, adata);
    *ra_cnt += 1;
    write(1, "ra\n", 3);
}

void rb(t_stack *b, int *rb_cnt)
{
    int bdata;

    if (b->next == NULL)
        return;
    bdata = b->next->data;
    ft_pop(b);
    ft_push_last(b, bdata);
    *rb_cnt += 1;
    write(1, "rb\n", 3);
}
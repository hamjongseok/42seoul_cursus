/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:34:58 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/05/14 00:54:21 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void pa(t_stack *a, t_stack *b, int *pa_cnt)
{
    int bsize;
    int bdata;

    bsize = ft_size(b);
    if (bsize < 1)
        return;
    bdata = b->next->data;
    ft_pop(b);
    ft_push_first(a, bdata);
    *pa_cnt += 1;
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b, int *pb_cnt)
{
    int asize;
    int adata;

    asize = ft_size(a); //노드의 길이 반환
    if (asize < 1)
        return;
    adata = a->next->data;
    ft_pop(a);               //탑 노드 연결 해제
    ft_push_first(b, adata); //b 에다가 adata의 노드를 만들어줌
    *pb_cnt += 1;
    write(1, "pb\n", 3);
}
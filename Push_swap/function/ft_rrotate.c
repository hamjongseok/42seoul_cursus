/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:57:29 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/05/14 14:39:44 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void rra(t_stack *a)
{
    t_stack *last_a;
    int adata;

    last_a = ft_find_last_lst(a); //마지막 노드 받음 1 받음
    adata = last_a->data;         //1
    ft_pop_last(a);               // a - 2- 8 - 1에서 1이 끊기고 a - 2 - 8이 된다
    ft_push_first(a, adata);      //1을 먼저 저장시켜놨으니간 앞에다가 붙이기만하면된다. 넣으니간 push
    write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
    t_stack *last_b;
    int bdata;

    last_b = ft_find_last_lst(b);
    bdata = last_b->data;
    ft_pop_last(b);
    ft_push_first(b, bdata);
    write(1, "rrb\n", 4);
}
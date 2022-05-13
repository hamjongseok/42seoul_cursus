/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:46:08 by jham              #+#    #+#             */
/*   Updated: 2022/05/14 00:58:56 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_m_change(t_stack *a, t_stack *b, int pb_cnt, int max_v)
{
    int idx;

    idx = 0; //idx 가 대체왜필요한거야 ?
    while (pb_cnt > 0)
    {
        if (b->next->data == max_v)
        {
            pa(a, b, &idx);
            ra(a, &idx);
        }
        else
            pa(a, b, &idx);
        pb_cnt -= 1;
    }
}

void ft_factor_five(t_stack *a, t_stack *b)
{
    int max_value;
    int min_value;
    int pb_cnt;
    int idx;

    idx = 0;
    max_value = ft_find_max(a); //8
    min_value = ft_find_min(a); //3
    pb_cnt = 0;
    while (ft_size(a) > 3) //4, 5가 들어온단건데 3은 어디서하지 ?
    {
        if (a->next->data == max_value ||
            a->next->data == min_value)
        {
            pb(a, b, &idx); //a의 첫번째 상위원소를 b의 첫번째 상위원소로 넣음
            pb_cnt += 1;    //밑에 체인지 함수에서 넣으려고 씀
        }
        else
            ra(a, &idx); //min,max값 못찾을 때 들어와서 수행,인덱스값?
    }
    ft_factor_three(a);
    ft_m_change(a, b, pb_cnt, max_value); //비에있는걸 넣어줌
}
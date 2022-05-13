/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:46:08 by jham              #+#    #+#             */
/*   Updated: 2022/05/13 14:56:12 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
            pb(a, b, &idx);
            pb_cnt += 1;
        }
        else
            ra(a, &idx); //min,max값 못찾을 때 들어와서 수행,인덱스값?
    }
    ft_factor_three(a);
}
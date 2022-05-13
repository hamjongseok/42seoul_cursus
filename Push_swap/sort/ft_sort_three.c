/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:56:32 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/05/13 20:49:47 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_factor_three(t_stack *head) //인수가 세개일때 여기로들어옴
{
    t_stack *top;
    t_stack *bot;
    int idx;
    int max_value;
    int min_value;

    idx = 0;
    top = head->next;                                               //2
    bot = head->next->next->next;                                   //6
    max_value = ft_find_max(head);                                  //숫자를 반환해줌 6
    min_value = ft_find_min(head);                                  // 1
    if ((top->next->data == min_value && bot->data == max_value) || //위, 아래를 바꿔줘야할상황 을 생각해보면 나온다.
        (top->data == max_value && bot->data == min_value) || (top->data == min_value && top->next->data == max_value))
    {
        sa(head);
    }
    //if (top->next->data == max_value)
    //  rra(head);
    if (top->data == max_value && top->next->data == min_value) //당연한것
        ra(head, &idx);
}
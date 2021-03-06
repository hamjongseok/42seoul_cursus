/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham <jham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:01:27 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/05/11 11:23:42 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_factor_two(t_stack *head) //원소값이 두개일때 들어오는 함수 
{
    t_stack *first;
    t_stack *second;
    //의문인게 정렬이 안되있으면 들어오는거아닌가 왜 if로 구분하는거지 ?  
    first = head->next;
    second = head->next->next;
    if (first->data > second->data)
            sa(head);
    else    
        return;
}
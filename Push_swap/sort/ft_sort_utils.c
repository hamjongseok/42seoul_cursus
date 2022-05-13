/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham <jham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:54:50 by jham              #+#    #+#             */
/*   Updated: 2022/05/11 12:10:48 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_find_max(t_stack *head)
{
    int max_value;

    max_value = -2147483648; //int형 max min, 최소점을 기준으로 
    head = head->next; 
    while (head)
    {
        if (max_value <= head->data) //-2147483648 보다 값이 크거나 같으면 
            max_value = head->data; //넣어준다 그값을 
        head = head->next; //계속 돌리기 
    }
    return (max_value); // 맥스 값 반환
}

int ft_find_min(t_stack *head) //min값 찾기 
{
    int min_value;

    min_value = 2147483647;
    head = head->next;
    while (head)
    {
        if (min_value >= head->data)
            min_value = head->data;
        head = head->next;
    }
    return(min_value);
}
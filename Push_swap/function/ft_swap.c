/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham <jham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:47:47 by jham              #+#    #+#             */
/*   Updated: 2022/05/11 11:15:59 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void sa(t_stack *a) //a스택의 상위 두 원소의 위치를 swap
{
    int data;
    int size;

    size = ft_size(a); //a의 길이를 구한다. 근데 굳이 왜구하지 ? 
    if (size < 2)
        return ;
    data = a->next->next->data; // 그냥 swap해주는것 
    a->next->next->data = a->next->data;
    a->next->data = data;
    write(1, "sa\n", 3);
}
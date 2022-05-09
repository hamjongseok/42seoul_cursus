/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:29:24 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/05/09 15:08:27 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_make_list(t_stack *head, long long *arr, int cnt)
{
    int idx;
    t_stack *new_node;

    idx = 0;
    while (idx < cnt)
    {
        new_node = (t_stack *)malloc(sizeof(t_stack));
        if (!new_node)
            ft_error(0);
        if (head->next == NULL)
        {
            new_node->data = arr[idx++];
            new_node->next = NULL;
            new_node->prev = head;
            head->next = new_node;
        }
        else
        {
            new_node->data = arr[idx++];
        }
    }
}
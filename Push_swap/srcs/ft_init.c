/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:54:14 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/04/06 17:54:29 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack *ft_stack_init(void)
{
    t_stack *tmp;

    tmp = (t_stack *)malloc(sizeof(t_stack));
    if (!tmp)
        ft_error(0);
    tmp->prev = NULL;
    tmp->data = 0;
    tmp->next = NULL;
    return (tmp);
}
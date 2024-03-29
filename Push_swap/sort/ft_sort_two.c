/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:01:27 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/05/18 12:41:22 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_factor_two(t_stack *head)
{
	t_stack		*first;
	t_stack		*second;

	first = head->next;
	second = head->next->next;
	if (first->data > second->data)
		sa(head);
	else
		return ;
}

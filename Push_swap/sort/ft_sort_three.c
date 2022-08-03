/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham <jham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:56:32 by jham              #+#    #+#             */
/*   Updated: 2022/05/18 12:40:17 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_factor_three(t_stack *head)
{
	t_stack		*top;
	t_stack		*bot;
	int			idx;
	int			max_value;
	int			min_value;

	idx = 0;
	top = head->next;
	bot = head->next->next->next;
	max_value = ft_find_max(head);
	min_value = ft_find_min(head);
	if ((top->next->data == min_value && bot->data == max_value)
		|| (top->data == max_value && bot->data == min_value)
		|| (top->data == min_value && top->next->data == max_value))
	{
		sa(head);
	}
	if (top->next->data == max_value)
		rra(head);
	if (top->data == max_value && top->next->data == min_value)
		ra(head, &idx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham <jahm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:47:47 by jham              #+#    #+#             */
/*   Updated: 2022/05/18 13:28:49 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack *a)
{
	int		data;
	int		size;

	size = ft_size(a);
	if (size < 2)
		return ;
	data = a->next->next->data;
	a->next->next->data = a->next->data;
	a->next->data = data;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int		data;
	int		size;

	size = ft_size(b);
	if (size < 2)
		return ;
	data = b->next->next->data;
	b->next->next->data = b->next->data;
	b->next->data = data;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

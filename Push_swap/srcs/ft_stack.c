/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham <jham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:55:26 by jham              #+#    #+#             */
/*   Updated: 2022/05/18 12:03:53 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push_first(t_stack *head, int data)
{
	t_stack		*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_error(0);
	if (head->next == NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = head;
		head->next = new_node;
	}
	else
	{
		new_node->data = data;
		new_node->next = head->next;
		head->next->prev = new_node;
		new_node->prev = head;
		head->next = new_node;
	}
}

int	ft_size(t_stack *head)
{
	t_stack		*tmp;
	int			size;

	size = 0;
	tmp = head->next;
	while (tmp)
	{
		tmp = tmp->next;
		size += 1;
	}
	return (size);
}

void	ft_push_last(t_stack *head, int data)
{
	t_stack		*new_node;
	t_stack		*tmp_last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_error(0);
	tmp_last = ft_find_last_lst(head);
	if (head->next == NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = head;
		head->next = new_node;
	}
	else
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = tmp_last;
		tmp_last->next = new_node;
	}
}

void	ft_pop(t_stack *head)
{
	t_stack	*del;

	del = head->next;
	if (del == NULL)
		return ;
	if (del->next == NULL)
	{
		head->next = del->next;
		free(del);
	}
	else
	{
		del->next->prev = head;
		head->next = del->next;
		free(del);
	}
}

void	ft_pop_last(t_stack *head)
{
	t_stack	*del;

	del = head->next;
	if (del == NULL)
		return ;
	else
	{
		del = ft_find_last_lst(head);
		del->prev->next = NULL;
		free(del);
	}
}

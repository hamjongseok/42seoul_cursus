/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham        <jham@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:54:50 by jham              #+#    #+#             */
/*   Updated: 2022/05/18 12:46:33 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_find_max(t_stack *head)
{
	int	max_value;

	max_value = -2147483648;
	head = head->next;
	while (head)
	{
		if (max_value <= head->data)
			max_value = head->data;
		head = head->next;
	}
	return (max_value);
}

int	ft_find_min(t_stack *head)
{
	int		min_value;

	min_value = 2147483647;
	head = head->next;
	while (head)
	{
		if (min_value >= head->data)
			min_value = head->data;
		head = head->next;
	}
	return (min_value);
}

void	ft_swap(long long *arr, int idx, int l_idx)
{
	int		tmp;

	tmp = arr[idx];
	arr[idx] = arr[l_idx];
	arr[l_idx] = tmp;
}

void	ft_sort_arr(long long *arr, int cnt)
{
	int		idx;
	int		jdx;
	int		least;
	int		least_idx;

	idx = 0;
	while (idx < cnt - 1)
	{
		least = arr[idx];
		least_idx = idx;
		jdx = idx + 1;
		while (jdx < cnt)
		{
			if (least > arr[jdx])
			{
				least = arr[jdx];
				least_idx = jdx;
			}
			jdx++;
		}
		ft_swap(arr, idx, least_idx);
		idx++;
	}
}

int	ft_find_pivot(t_stack *head, int cnt)
{
	t_stack		*tmp;
	long long	*arr;
	int			idx;
	int			result;

	tmp = head->next;
	arr = (long long *)malloc(sizeof(long long) * cnt);
	idx = 0;
	while (idx < cnt)
	{
		arr[idx++] = tmp->data;
		tmp = tmp->next;
	}
	idx = 0;
	ft_sort_arr(arr, cnt);
	result = arr[cnt / 2];
	free(arr);
	return (result);
}

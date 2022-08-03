/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:46:05 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/05/19 15:44:21 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_check_factor(t_stack *a, t_stack *b, int num)
{
	if (num == 1)
		return ;
	else if (num == 2)
		ft_factor_two(a);
	else if (num > 2 && num < 6)
		ft_factor_five(a, b);
	else
		ft_a_b(a, b, num);
}

void	ft_check_sort(long long *int_arr, int arr_size)
{
	int	idx;

	idx = arr_size - 1;
	while (idx > 0)
	{
		if (int_arr[idx] > int_arr[idx - 1])
			return ;
		idx--;
	}
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;			
	long long	*int_arr;
	int			arr_size;		

	if (argc < 2)
		exit(0);
	a = ft_stack_init();
	b = ft_stack_init();
	arr_size = ft_input_num(argv, argc);
	int_arr = (long long *)malloc(sizeof(long long) * arr_size);
	if (!int_arr)
		ft_error(0);
	ft_init_arr(argv, int_arr, argc, arr_size);
	if (!(ft_check_arr(int_arr, arr_size)))
		ft_error(0);
	ft_check_sort(int_arr, arr_size);
	ft_make_list(a, int_arr, arr_size);
	ft_check_factor(a, b, arr_size);
	system("leaks push_swap"); //메모리 누수확인
	return (0);
}

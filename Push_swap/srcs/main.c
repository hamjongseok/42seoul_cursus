/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:46:05 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/04/14 13:26:17 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void ft_check_sort(long long *int_arr, int arr_size)
{
	int idx;

	idx = arr_size - 1; //4  idx = 3
	while (idx > 0)		// 3 > 0
	{
		if (int_arr[idx] > int_arr[idx - 1]) //3 > 2
			return;
		idx--;
	}
	exit(0);
}

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;			//stack a와 b를 만들어줌
	long long *int_arr; // 온전한 숫자가 들어오게하기위해 아토이에서 인트를 벗어나면 숫자가 변형되는것을 방지
	int arr_size;		// 이것도 모름, array의 크기 즉 배열의 크기란건데

	if (argc < 2) // argc가 1일때는 필요없기때문에 예외처리로 끝내준다
		exit(0);
	a = ft_stack_init();				 //초기화 해주는 함수 초기화를 해준다.
	b = ft_stack_init();				 // 앞뒤 널을 가리키고 data가 0인 노드 a,b 2개 생김
	arr_size = ft_input_num(argv, argc); // 총 노드의 개수라고 해야하나.
	int_arr = (long long *)malloc(sizeof(long long) * arr_size);
	if (!int_arr)
		ft_error(0);
	ft_init_arr(argv, int_arr, argc, arr_size); //long long 포인터인 int_arr에 숫자들을 넣음, 이과정에서 문자가 들어있는지 검사 (atoll함수)
	if (!(ft_check_arr(int_arr, arr_size)))		//인트검사, 숫자 중복검사
		ft_error(0);
	int i = 0;
	while (i < 4)
	{
		printf("int_arr[%d]= %lld\n", i, int_arr[i]);
		i++;
	}
	ft_check_sort(int_arr, arr_size);
	return (0);
}

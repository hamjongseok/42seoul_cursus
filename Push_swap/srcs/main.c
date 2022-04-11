/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:46:05 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/04/11 19:12:35 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;			//stack a와 b를 만들어줌
	long long *int_arr; // 아직뭐하는 애인지 모르겠음, 아마도 int범위 내의 값을 받아주기위해? 음수를 받아주기위해쓰는건가?
	int arr_size;		// 이것도 모름, array의 크기 즉 배열의 크기란건데

	if (argc < 2) // argc가 1일때는 필요없기때문에 예외처리로 끝내준다
		exit(0);
	a = ft_stack_init();				 //초기화 해주는 함수 초기화를 해준다.
	b = ft_stack_init();				 // 앞뒤 널을 가리키고 data가 0인 노드 a,b 2개 생김
	arr_size = ft_input_num(argv, argc); // 총 노드의 개수라고 해야하나.
	int_arr = (long long *)malloc(sizeof(long long) * arr_size);
	if (!int_arr)
		ft_error(0);
	return (0);
}

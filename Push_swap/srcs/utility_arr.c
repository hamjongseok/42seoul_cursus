/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:12:04 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/04/13 19:47:32 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_check_arr(long long *arr, int arr_size)
{
    int i;
    int j;

    i = 0;
    while (i < arr_size) //6  0 1 2 3 4 5
    {
        j = i + 1; //첫번째와 두번째를 비교하기위해

        if (arr[i] > 2147483647 || arr[i] < -2147483648)
            ft_error(0); //int 범위를 벗어난다면 에러 표시
        while (j < arr_size)
        {
            if (arr[i] == arr[j]) //숫자 중복 검사
                ft_error(0);
            j++;
        }
        i++;
    }
    return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:54:50 by jham              #+#    #+#             */
/*   Updated: 2022/05/14 14:32:04 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_find_max(t_stack *head)
{
    int max_value;

    max_value = -2147483648; //int형 max min, 최소점을 기준으로
    head = head->next;
    while (head)
    {
        if (max_value <= head->data) //-2147483648 보다 값이 크거나 같으면
            max_value = head->data;  //넣어준다 그값을
        head = head->next;           //계속 돌리기
    }
    return (max_value); // 맥스 값 반환
}

int ft_find_min(t_stack *head) //min값 찾기
{
    int min_value;

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

void ft_swap(long long *arr, int idx, int l_idx)
{
    int tmp;

    tmp = arr[idx];
    arr[idx] = arr[l_idx];
    arr[l_idx] = tmp;
}

void ft_sort_arr(long long *arr, int cnt)
{
    int idx;
    int jdx;
    int least;
    int least_idx;

    idx = 0;
    while (idx < cnt - 1) //0 < 5
    {
        least = arr[idx]; // 3
        least_idx = idx;  // 0
        jdx = idx + 1;    // 1
        while (jdx < cnt) // 1 < 6
        {
            if (least > arr[jdx]) // 옆에꺼랑 비교할라고
            {
                least = arr[jdx];
                least_idx = jdx; //바꿔야할 기준점을 준다
            }
            jdx++;
        }
        ft_swap(arr, idx, least_idx);
        idx++;
    }
}

int ft_find_pivot(t_stack *head, int cnt) //a와 총 길이수
{
    t_stack *tmp;
    long long *arr;
    int idx;
    int result;

    tmp = head->next;                                   //top을 넘김
    arr = (long long *)malloc(sizeof(long long) * cnt); //리스트를 생성
    idx = 0;
    while (idx < cnt)
    {
        arr[idx++] = tmp->data;
        tmp = tmp->next;
    } //생성한 리스트에다가 a 값을 다 넣음
    idx = 0;
    ft_sort_arr(arr, cnt);
    result = arr[cnt / 2];
    free(arr);
    return (result);
}
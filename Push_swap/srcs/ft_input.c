/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:26:05 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/04/13 15:37:36 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_split_arr_size(char **split_arr)
{
    int idx;

    idx = 0;
    while (split_arr[idx])
        idx++;
    return (idx);
}

void free_str(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

int ft_input_num(char **av, int ac) //
{
    int size;
    int i; //인덱스
    int split_size;
    char **split_arr; //자를거 다자르고 남은 최종 문자열인건가

    size = 0;
    i = 0;
    while (i < ac) //실행부터 들어가는것 고쳐야겠다.
    {
        split_arr = ft_split(av[i], ' ');
        split_size = ft_split_arr_size(split_arr); //split_Arr size를 구함
        size += split_size;
        free_str(split_arr); //다음 을 위해 free해줌
        i++;
    }
    return (size - 1); //av[0], 실행 명령어가 들어가기때문에 -1 해준다
}

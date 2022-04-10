/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:26:05 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/04/08 17:56:31 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_input_num(char **av, int ac) //왜 int형이지? 매개변수로 인자값이 들어옴
{
    int size;
    int i; //인덱스
    int split_size;
    char **split_arr; //자를거 다자르고 남은 최종 문자열인건가

    size = 0;
    i = 0;
    while (i < ac) //실행부터 들어가는건데..?
    {
        split_arr = ft_split(av[i], ' ');
        i++;
    }
    return (0);
}

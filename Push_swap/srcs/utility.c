/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:51:41 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/04/11 21:54:38 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_error(int c)
{
    write(1, "Error\n", 6);
    exit(c);
    return (c);
}

int ft_isspace(char c)
{
    return (c == '\f' || c == '\n' || c == 'r' ||
            c == '\t' || c == '\v' || c == ' ');
}

long long ft_atoll(char *str)
{
    long long result;
    int sign;

    result = 0;
    sign = 1;
    while (ft_isspace(*str))
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str++ == '-')
            sign *= -1;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    if (ft_isalpha(*str))
        ft_error(0);
    return (sign * result);
}
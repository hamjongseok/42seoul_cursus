/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:04:30 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/01/21 12:14:12 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_intsize(int n) //왜필요한거지 ? 123
{
    int i;

    if (n > 0)
        i = 0; //아이거는 그거네 -가 있는지없는지 판별하려고
    else
        i = 1;
    while (n != 0) //123 을 10으로 계속 쪼갬
    {
        n /= 10; //12, 1   1, 2 ㅑ == 3
        i++;
    }
    return (i);
}

char *ft_itoa(int n)
{
    int len;
    long long num;
    char *result;
    char *res;

    num = n;
    len = ft_intsize(n);                               // 3
    result = (char *)malloc(sizeof(char) * (len + 1)); //말록으로 할당해줌 3 개 + 널자리 1
    if (!result)
    {
        free(result);
        return (NULL);
    }
    result[len--] = '\0'; //마지막에 널 할당
    if (num < 0)
    {
        num *= -1;
        result[0] = '-';
    }
    if (n == 0)
        result[0] = '0';
    while (num > 0)
    {
        result[len--] = (num % 10) + '0';
        num /= 10;
    }
    res = result;
    free(result);
    return (res);
}

int ft_print_di(va_list *ap)
{
    char *res;
    int nbr;
    int i;

    i = 0;
    nbr = va_arg(*ap, int);
    res = ft_itoa(nbr);
    while (res[i] != '\0')
    {
        write(1, &res[i], 1);
        i++;
    }
    return (i);
}
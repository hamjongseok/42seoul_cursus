/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:04:30 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/01/21 14:08:46 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_intsize(int n) 
{
    int i;

    if (n > 0)
        i = 0; 
    else
        i = 1;
    while (n != 0) 
    {
        n /= 10;
        i++;
    }
    return (i);
}

char *ft_itoa(int n)
{
    int len;
    long long num;
    char *result;

    num = n;
    len = ft_intsize(n);
    result = (char *)malloc(sizeof(char) * (len + 1)); 
    if (!result)
        return (NULL);
    result[len--] = '\0'; 
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
    return (result);
}

int ft_print_di(va_list *ap)
{
    char *res;
    int nbr;
    int i;

    i = 0;
    nbr = va_arg(*ap, int);
    res = ft_itoa(nbr);
	if (res == 0)
		return (-1);
    while (res[i] != '\0')
    {
        write(1, &res[i], 1);
        i++;
    }
    free(res);
    return (i);
}

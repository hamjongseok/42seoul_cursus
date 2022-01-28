/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:09:34 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/01/28 15:09:39 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_intsize_u(unsigned int n)
{
    int i;

    i = 0;
    if (n == 0)
        i = 1;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char *ft_itoa_u(unsigned int n)
{
    int len;
    unsigned int num;
    char *result;

    num = n;
    len = ft_intsize_u(n);
    result = (char *)malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    result[len--] = '\0';
    if (n == 0)
        result[0] = '0';
    while (num > 0)
    {
        result[len--] = (num % 10) + '0';
        num /= 10;
    }
    return (result);
}

int ft_print_u(va_list *ap)
{
    int i;
    unsigned int nbr;
    char *res;

    i = 0;
    nbr = va_arg(*ap, int);
    res = ft_itoa_u(nbr);
    while (res[i] != '\0')
    {
        write(1, &res[i], 1);
        i++;
    }
    free(res);
    return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:07:18 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/01/25 15:42:01 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}

int ft_print_xx(va_list *ap)
{
    char *str;
    char c;
    unsigned int res;
    int i;

    i = 0;
    res = (unsigned int)va_arg(*ap, unsigned int);
    str = ft_restohex(res);
    if (!str)
        return (-1);
    while (str[i])
    {
        c = ft_toupper(str[i]);
        write(1, &c, 1);
        i++;
    }
    free(str);
    return (i);
}

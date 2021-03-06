/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:09:21 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/01/28 15:09:28 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_p(va_list *ap)
{
    size_t res;
    char *str;
    int i;

    i = 0;
    res = (size_t)va_arg(*ap, void *);
    str = ft_restohex(res);
    if (!str)
        return (-1);
    write(1, "0x", 2);
    while (str[i])
    {
        write(1, str + i, 1);
        i++;
    }
    free(str);
    return (i + 2);
}

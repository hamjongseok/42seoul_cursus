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
    char *cp;
    char c;
    unsigned int dec;
    int i;

    i = 0;
    dec = (unsigned int)va_arg(*ap, unsigned int);
    cp = ft_dectohex(dec);
    if (!cp)
        return (0);
    while (cp[i])
    {
        c = ft_toupper(cp[i]);
        write(1, &c, 1);
        i++;
    }
    free(cp);
    return (i);
}
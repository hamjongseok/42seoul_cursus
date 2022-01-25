/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upperx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:07:18 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/01/25 13:13:57 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t pow_hex(int n)
{
    size_t ret;

    ret = 1;
    while (n--)
        ret *= 16;
    return (ret);
}

static int hex_len(size_t dec)
{
    int c;

    c = 1;
    while (dec > 15)
    {
        dec /= 16;
        c++;
    }
    return (c);
}

char *ft_dectohex(size_t res)
{
    char *cp;
    int len;
    int i;
    size_t tmp;
    char *g_hex;

    g_hex = "0123456789abcdef";
    i = 0;
    len = hex_len(res);
    cp = (char *)malloc(sizeof(char) * (len + 1));
    if (!cp)
        return (0);
    while (len > 0)
    {
        tmp = pow_hex(len - 1);
        cp[i++] = g_hex[res / tmp];
        res %= tmp;
        len--;
    }
    cp[i] = '\0';
    return (cp);
}

char ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}

int print_upperx(va_list *ap)
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
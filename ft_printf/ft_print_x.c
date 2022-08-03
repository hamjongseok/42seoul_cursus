/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:40:19 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/01/26 12:52:15 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pow_hex(int n)
{
    size_t	ret;

    ret = 1;
    while (n--)
        ret *= 16;
    return (ret);
}

int ft_hex_len(size_t res)
{
    int i;

    i = 1; 
    while (res > 15)
    {
        res /= 16;
        i++;
    }
    return (i);
}

char *ft_restohex(size_t res)
{
    char *str;
    int len;
    int i;
    size_t pow;
    char *hex_str;

    hex_str = "0123456789abcdef";
    i = 0;
    len = ft_hex_len(res);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (0);
    while (len > 0)
    {
        pow = ft_pow_hex(len - 1);
		str[i] = hex_str[res / pow]; 
        res %= pow; 
        len--;
        i++;
    }
    str[i] = '\0';
    return (str);
}

int ft_print_x(va_list *ap)
{
    char *str;
    unsigned int res;
    int i;

    i = 0;
    res = va_arg(*ap, unsigned int); 
    str = ft_restohex(res);
    if (!str)
        return (-1);
    while (str[i])
    {
        write(1, str + i, 1);
        i++;
    }
    free(str);
    return (i);
}

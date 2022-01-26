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

static size_t pow_hex(int n)
{
    size_t ret;

    ret = 1;
    while (n--)
        ret *= 16;
    return (ret);
}

static int hex_len(size_t res)
{
    int i;

    i = 1; //나머지 가 필요없다면 16보다 작다면 어차피 1이니간 , 그게아니라면 나머지를 구해줘야하니간 1
    while (res > 15)
    {
        res /= 16;
        i++;
    }
    return (i);
}

char *ft_dectohex(size_t res)
{
    char *cp;
    int len;
    int i;
    size_t pow; //%p 때문에 해줘야한다.
    char *g_hex;

    g_hex = "0123456789abcdef";
    i = 0;
    len = hex_len(res);
    cp = (char *)malloc(sizeof(char) * (len + 1));
    if (!cp)
        return (0);
    while (len > 0)
    {
        pow = pow_hex(len - 1); //256
        cp[i] = g_hex[res / pow];
        res %= pow;
        len--;
        i++;
    }
    cp[i] = '\0';
    return (cp);
}

int ft_print_x(va_list *ap) //26을 가리키고 있는 ap가 들어왔다.
{
    char *cp;
    unsigned int res;
    int i;

    i = 0;
    res = va_arg(*ap, unsigned int); //정수를 받음
    cp = ft_dectohex(res);           //문자열 cp에 정수를 16진수로 바꾼 문자열을 받는다.
    if (!cp)
        return (0);
    while (cp[i])
    {
        write(1, cp + i, 1);
        i++;
    }
    free(cp);
    return (i);
}
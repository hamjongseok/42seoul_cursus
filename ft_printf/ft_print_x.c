#include "ft_printf.h"
#include <stdio.h>

int ft_putchar(char c, int a)
{
    write(1, &c, 1);
    a++;
    return (a);
}

int ft_hex_per(int na, int cnt)
{
    if (na == 10)
        ft_putchar('a', cnt);
    else if (na == 11)
        ft_putchar('b', cnt);
    else if (na == 12)
        ft_putchar('c', cnt);
    else if (na == 13)
        ft_putchar('d', cnt);
    else if (na == 14)
        ft_putchar('e', cnt);
    else if (na == 15)
        ft_putchar('f', cnt);
    else
        ft_putchar(na + '0', cnt);
}

int ft_hex_x(int a)
{
    int mok;
    int na;
    int cnt;

    cnt = 0;
    mok = a / 16;
    if (mok > 16) //77
    {
        mok = a / 16;
        ft_putchar(mok + '0', cnt);
    }
    else
        ft_putchar(mok + '0', cnt);
    na = a % 16;
    ft_hex_per(na, cnt);
    return (cnt);
}

int ft_print_x(va_list *ap) //26을 가리키고 있는 ap가 들어왔다.
{
    unsigned int res;
    int cnt;

    res = va_arg(*ap, unsigned int); //정수를 받음
    cnt = ft_hex_x(res);             //이해가안가는게 영어가 뒤에 붙는데 이것도 그냥 int로 처리하는건가 ?

    return (cnt);
}
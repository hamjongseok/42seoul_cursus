#include "ft_printf.h"
#include <stdio.h>

int ft_hex_x(int a)
{
    char *str;
    char b;
    int mok;

    if (a < 9)
    {
        b = a + '0';
        write(1, &b, 1);
        return (1);
    }
    else
    {
        mok = a / 16;
    }
}

int ft_print_x(va_list *ap) //26을 가리키고 있는 ap가 들어왔다.
{
    int res;

    res = va_arg(*ap, int); //26을 res가 받음,  이제 26을 16진수로 변환해야한다.
    printf("res = %d\n", res);
    res = ft_hex_x(res); //이해가안가는게 영어가 뒤에 붙는데 이것도 그냥 int로 처리하는건가 ?

    return (res);
}
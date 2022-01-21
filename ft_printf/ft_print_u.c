#include "ft_printf.h"
#include <stdio.h>

int ft_intsize_u(unsigned int n) //왜필요한거지 ? 123
{
    int i;

    i = 0;
    if (n == 0) //0이라면 쓰레기값이 들어오기때문에 밑에서 널 넣고 0도 넣어줘서 널이 들어가지않는다. 그렇기때문에 예외처리해줌
        i = 1;
    while (n != 0) //123 을 10으로 계속 쪼갬
    {
        n /= 10; //12, 1   1, 2 ㅑ == 3
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
    len = ft_intsize_u(n);                             // 3
    result = (char *)malloc(sizeof(char) * (len + 1)); //말록으로 할당해줌 3 개 + 널자리 1
    if (!result)
        return (NULL);
    result[len--] = '\0'; //마지막에 널 할당
    if (n == 0)
        result[0] = '0';
    while (num > 0)
    {
        result[len--] = (num % 10) + '0';
        num /= 10;
    }
    return (result);
}

int ft_print_u(va_list *ap) //-1
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
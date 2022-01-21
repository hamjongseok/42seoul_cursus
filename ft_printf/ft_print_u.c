#include "ft_printf.h"

int ft_intsize_u(int n) //왜필요한거지 ? 123
{
    int i;

    i = 0;
    while (n != 0) //123 을 10으로 계속 쪼갬
    {
        n /= 10; //12, 1   1, 2 ㅑ == 3
        i++;
    }
    return (i);
}

char *ft_itoa_u(int n)
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
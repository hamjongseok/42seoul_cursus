#include "ft_printf.h"

int ft_print_p(va_list *ap)
{
    size_t res;
    char *cp;
    int i;

    i = 0;
    res = (size_t)va_arg(*ap, void *);
    cp = ft_dectohex(res);
    if (!cp)
        return (-1);
    write(1, "0x", 2);
    while (cp[i])
    {
        write(1, cp + i, 1);
        i++;
    }
    free(cp);
    return (i + 2);
}
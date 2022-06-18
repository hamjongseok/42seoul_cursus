
#include "../pipex.h"

void *ft_bzero(void *str, size_t n)
{
    unsigned char *ptr_str;
    size_t i;

    ptr_str = str;
    i = 0;
    while (i < n)
    {
        *ptr_str = 0;
        ptr_str++;
        i++;
    }
    return (str);
}

size_t ft_strlcpy(char *dst, const char *src, size_t len)
{
    size_t src_len;
    size_t i;

    src_len = 0;
    i = 0;
    while (src[src_len])
        src_len++;
    if (len == 0)
    {
        return (src_len);
    }
    while (i < len - 1 && *src)
    {
        *dst = *src;
        dst++;
        src++;
        i++;
    }
    *dst = '\0';
    return (src_len);
}
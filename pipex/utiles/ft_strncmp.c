
#include "../pipex.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char *ptr_s1;
    unsigned char *ptr_s2;

    ptr_s1 = (unsigned char *)s1; //PATH=
    ptr_s2 = (unsigned char *)s2; //envp
    while (n > 0)                 // 5 4 3 2 1
    {
        if (*ptr_s1 == *ptr_s2) //두개다 패치인지
        {
            ptr_s1++;
            ptr_s2++;
            n--;
        }
        else
        {
            return (*ptr_s1 - *ptr_s2); //같지 않다면
        }
        if (!(*ptr_s1) && !(*ptr_s2)) // ???
            break;
    }
    return (0);
}
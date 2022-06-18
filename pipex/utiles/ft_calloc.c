
#include "../pipex.h"

void *ft_calloc(size_t n, size_t size)
{
    char *new_mem;
    size_t length;

    new_mem = NULL;
    length = size * n;
    if (length == 0)
    {
        new_mem = malloc(0);
        return (new_mem);
    }
    if (length / n != size || length % size != 0)
        exit_perror("memory allocation fail", 1);
    new_mem = malloc(length);
    if (!(new_mem))
        exit_perror("memory allocation fail", 1);
    ft_bzero(new_mem, length);
    return (new_mem);
}
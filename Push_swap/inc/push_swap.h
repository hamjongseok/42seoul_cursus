#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	t_list *a;
	t_list *b;
} t_stack;

void print_stack(t_list *a);

#endif
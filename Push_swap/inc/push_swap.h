#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	struct s_stack *prev;
	int data;
	struct s_stack *next;
} t_stack;

t_stack *ft_stack_init(void);

#endif
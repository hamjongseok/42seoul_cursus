#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	struct s_stack *prev;
	int data;
	struct s_stack *next;
} t_stack;

int ft_input_num(char **av, int ac);
t_stack *ft_stack_init(void);
char **ft_split(char const *s, char c);
int ft_error(int c);

#endif
#include "../inc/push_swap.h"

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	long long *int_arr;
	int arr_size;

	if (argc < 2)
		exit(0);
	a = ft_stack_init(); //a, b를 초기화
	b = ft_stack_init();

	arr_size = ft_input_num(argv, argc);

	return (0);
}

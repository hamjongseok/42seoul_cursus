/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:46:05 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/04/07 17:46:57 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void print_stack(t_list *a)
{
	while (a != NULL)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
}

int main(int argc, char *argv[])
{
	t_stack *box;
	t_list *tmp;
	int num;

	box = malloc(sizeof(t_stack));
	for (int i = 1; argv[i]; i++)
	{
		num = 0;
		num = atoi(argv[i]);
		tmp = ft_lstnew((void *)num);
		ft_lstadd_back(&(box->a), tmp);
	}

	print_stack(box->a);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham <jham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:21:25 by jham              #+#    #+#             */
/*   Updated: 2022/05/18 12:23:56 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				data;
	struct s_stack	*next;
}	t_stack;

long long	ft_atoll(char *str);
void		ft_init_arr(char **av, long long *int_arr, int ac, int arr_size);
void		free_str(char **str);
int			ft_split_arr_size(char **split_arr);
void		ft_make_list(t_stack *head, long long *arr, int cnt);
int			ft_size(t_stack *head);
t_stack		*ft_find_last_lst(t_stack *stack);
void		ft_pop(t_stack *head);
void		ft_push_last(t_stack *head, int data);
void		ft_push_first(t_stack *head, int data);
void		ft_pop_last(t_stack *head);
void		ft_m_change(t_stack *a, t_stack *b, int pb_cnt, int max_v);
void		ft_a_b(t_stack *a, t_stack *b, int cnt);
int			ft_find_pivot(t_stack *head, int cnt);
void		ft_sort_arr(long long *arr, int cnt);
void		ft_b_a(t_stack *a, t_stack *b, int cnt);
/*
** split.c
*/
char		**ft_split(char const *s, char c);

/*
** utils.c
*/
int			ft_error(int c);
int			ft_check_arr(long long *arr, int arr_size);

/*
** ft_init.c
*/
t_stack		*ft_stack_init(void);

/*
** ft_input.c
*/
int			ft_input_num(char **av, int ac);

/*
sort/ft_sort_five.c
*/
void		ft_factor_five(t_stack *a, t_stack *b);
int			ft_find_min(t_stack *head);
int			ft_find_max(t_stack *head);
void		ft_factor_three(t_stack *head);
void		ft_swap(long long *arr, int idx, int l_idx);

/*
function/ft_swap.c
*/
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

/*
fuction/ft_rotate.c
*/
void		ra(t_stack *a, int *ra_cnt);
void		rb(t_stack *b, int *rb_cnt);
void		rr(t_stack *a, t_stack *b);

/*
function/ft_rrotate.c
*/
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

/*
function/ft_push.c
*/
void		pb(t_stack *a, t_stack *b, int *pb_cnt);
void		pa(t_stack *a, t_stack *b, int *pa_cnt);
/*
** sort
*/
void		ft_factor_two(t_stack *head);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham <jham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:26:05 by jham              #+#    #+#             */
/*   Updated: 2022/05/18 11:55:06 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_split_arr_size(char **split_arr)
{
	int		idx;

	idx = 0;
	while (split_arr[idx])
		idx++;
	return (idx);
}

void	free_str(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_input_num(char **av, int ac)
{
	int		size;
	int		i;
	int		split_size;
	char	**split_arr;

	size = 0;
	i = 0;
	while (i < ac)
	{
		split_arr = ft_split(av[i], ' ');
		split_size = ft_split_arr_size(split_arr);
		size += split_size;
		free_str(split_arr);
		i++;
	}
	return (size - 1);
}

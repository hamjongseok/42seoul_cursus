/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham <jham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:51:41 by jham              #+#    #+#             */
/*   Updated: 2022/05/18 12:19:38 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_error(int c)
{
	write (1, "Error\n", 6);
	exit (c);
	return (c);
}

int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == 'r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_check_arr(long long *arr, int arr_size)
{
	int		i;
	int		j;

	i = 0;
	while (i < arr_size)
	{
		j = i + 1;
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
			ft_error(0);
		while (j < arr_size)
		{
			if (arr[i] == arr[j])
				ft_error(0);
			j++;
		}
		i++;
	}
	return (1);
}

long long	ft_atoll(char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (ft_isalpha(*str))
		ft_error(0);
	return (sign * result);
}

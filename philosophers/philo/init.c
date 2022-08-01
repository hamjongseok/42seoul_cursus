/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 05:22:49 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/08/02 05:24:56 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_arg_init(t_arg *arg, int argc, char *argv[])
{
  arg->philo_num = ft_atoi(argv[1]);
  arg->time_to_die = ft_atoi(argv[2]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 05:22:49 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/08/16 00:47:34 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_arg_init_mutex(t_arg *arg)
{
  int i;

  if (pthread_mutex_init(&(arg->print), NULL))
    return (1);
  arg->forks = malloc(sizeof(pthread_mutex_t) * arg->philo_num);
  if (!(arg->forks))
    return (1);
  i = 0;
  while (i < arg->philo_num)
  {
    if (pthread_mutex_init(&(arg->forks[i]), NULL))
      return (1);
    i++;
  }
  return (0);
}

int ft_arg_init(t_arg *arg, int argc, char *argv[])
{
  arg->philo_num = ft_atoi(argv[1]);
  arg->time_to_die = ft_atoi(argv[2]);
  arg->time_to_eat = ft_atoi(argv[3]);
  arg->time_to_sleep = ft_atoi(argv[4]);
  arg->start_time = ft_get_time();
  if (arg->philo_num <= 0 || arg->time_to_die < 0 || arg->time_to_eat < 0 || arg->time_to_sleep < 0)
    return (5); //왜 5지?
  if (argc == 6)
  {
    arg->eat_times = ft_atoi(argv[5]); //최소한의 먹어야하는 회수
    if (arg->eat_times <= 0)
      return (6); //왜 6?
  }
  if (ft_arg_init_mutex(arg)) //안에서 실패하면 1반환되므로
    return (1);
  return (0);
}

int ft_philo_init(t_philo **philo, t_arg *arg) //구조체 배열, 구조체
{
  int i;

  i = 0;
  *philo = malloc(sizeof(t_philo) * arg->philo_num);
  if (!(philo))
    return (1);
  while (i < arg->philo_num)
  {
    (*philo)[i].arg = arg;
    (*philo)[i].id = i; //이름대신 번호매기라고 서브젝트에 명시
    (*philo)[i].left = i;
    (*philo)[i].right = (i + 1) % arg->philo_num;
    (*philo)[i].last_eat_time = ft_get_time();
    (*philo)[i].eat_count = 0;
    i++;
  }
  return (0);
}
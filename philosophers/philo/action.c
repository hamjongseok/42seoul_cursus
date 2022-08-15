/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 03:27:38 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/08/15 23:04:00 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_pass_time(long long wait_time, t_arg *arg)
{
  long long start;
  long long now;

  start = ft_get_time();
  while (!(arg->finish))
  {
    now = ft_get_time();
    if ((now - start) >= wait_time)
      break;
    usleep(10); //시간밀림현상 해결 하기위한 예외처리
  }
}

int ft_philo_printf(t_arg *arg, int id, char *msg)
{
  long long now;

  now = ft_get_time();
  if (now == -1)
    return (-1);
  pthread_mutex_lock(&(arg->print));
  if (!(arg->finish))
    printf("%lld %d %s\n", now - arg->start_time, id + 1, msg);
  pthread_mutex_unlock(&(arg->print));
  return (0);
}

int ft_philo_action(t_arg *arg, t_philo *philo)
{
  pthread_mutex_lock(&(arg->forks[philo->left])); //한명이면 그냥 굶어주금
  ft_philo_printf(arg, philo->id, "has taken a fork");
  if (arg->philo_num != 1)
  {
    pthread_mutex_lock(&(arg->forks[philo->right]));
    ft_philo_printf(arg, philo->id, "has taken a fork");
    ft_philo_printf(arg, philo->id, "is eating");
    philo->last_eat_time = ft_get_time(); //먹기시작한 시간에 현재시간구해오는게맞음
    philo->eat_count = philo->eat_count + 1;
    ft_pass_time((long long)arg->time_to_eat, arg);    //다밥을 먹었는지
    pthread_mutex_unlock(&(arg->forks[philo->right])); //if문 안에서 lock했기때문에
  }
  pthread_mutex_unlock(&(arg->forks[philo->left]));
  return (0);
}
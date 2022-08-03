/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 04:44:31 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/08/03 01:58:39 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <sys/time.h>

typedef struct s_arg
{
  int philo_num;
  int time_to_die;
  int time_to_eat;
  int time_to_sleep;
  int eat_times;
  int finish;
  int finished_eat;
  long long start_time;
  pthread_mutex_t *forks; //왜두개나있지?
  pthread_mutex_t print;  //왜두개나있지?
} t_arg;

typedef struct s_philo
{
  struct s_arg *arg;
  pthread_t thread;
  int id;
  int left;
  int right;
  long long last_eat_time;
  int eat_count;
} t_philo;

#endif
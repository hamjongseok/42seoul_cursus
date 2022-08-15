/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 04:44:31 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/08/15 01:48:57 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_arg
{
  int philo_num;     //철학자 수
  int time_to_die;   //철학자의 수명
  int time_to_eat;   //밥먹는데 걸리는 시간
  int time_to_sleep; //잠자는 시간
  int eat_times;     //최소한 밥을 먹어야 하는 횟수,선택사항
  int finish;        //?
  int finished_eat;  //다먹은 철학자의 수
  long long start_time;
  pthread_mutex_t *forks; //포크 수
  pthread_mutex_t print;  //출력해햐 함으로.
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

int ft_philo_action(t_arg *arg, t_philo *philo);
int ft_philo_printf(t_arg *arg, int id, char *msg);
void ft_pass_time(long long wait_time, t_arg *arg);
long long ft_get_time(void);
int print_error(char *msg, int errno);
int ft_arg_init(t_arg *arg, int argc, char *argv[]);
int ft_philo_init(t_philo **philo, t_arg *arg);
int ft_atoi(char *str);

#endif
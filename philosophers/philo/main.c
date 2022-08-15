/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 04:42:07 by jham              #+#    #+#             */
/*   Updated: 2022/08/16 01:29:26 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_thread(void *argv)
{
  t_arg *arg;
  t_philo *philo;

  philo = argv;     //인자로 넘어온 철학자 @번의 정보
  arg = philo->arg; //인자로 넘어온 철학자의 arg
  if (philo->id % 2)
    usleep(1000); //1000마이크로초 ? -> 1초 쉬게하려고
  else
    usleep(500);       // 이거왜하는거지? 0.5초?
  while (!arg->finish) //처음에 0으로 초기화되었을테니 지금 1이다.
  {
    ft_philo_action(arg, philo);            //밥을 다먹음(fork집고, 밥먹는거까지나옴)
    if (arg->eat_times == philo->eat_count) //최소한의 밥먹는횟수와 철학자의 밥먹는수가 같다면
    {
      arg->finished_eat++; // 다먹은 철학자 수를 +1해줌, 모든철학자가 최소의 횟수를 다먹으면 프로그램은 종료되기때문에
      break;
    }
    ft_philo_printf(arg, philo->id, "is sleeping");   //다먹었으면 자야하기때문에
    ft_pass_time((long long)arg->time_to_sleep, arg); //다 잤으면
    ft_philo_printf(arg, philo->id, "is thinking");   //다 잤으면 생각한다.
  }
  return (0);
}

void ft_free_thread(t_arg *arg, t_philo *philo)
{
  int i;

  i = 0;
  while (i < arg->philo_num)
    pthread_mutex_destroy(&(arg->forks[i++]));
  free(philo);
  free(arg->forks);
  pthread_mutex_destroy(&(arg->print));
}

void ft_philo_check_finish(t_arg *arg, t_philo *philo)
{
  int i;
  long long now;

  while (!arg->finish)
  {
    if ((arg->eat_times != 0) && (arg->philo_num == arg->finished_eat))
    {
      arg->finish = 1;
      break;
    }
    i = 0;
    while (i < arg->philo_num)
    {
      now = ft_get_time();
      if ((now - philo[i].last_eat_time) >= arg->time_to_die)
      {
        ft_philo_printf(arg, i, "died");
        arg->finish = 1;
        break;
      }
      i++;
    }
  }
}

int ft_philo_start(t_arg *arg, t_philo *philo)
{
  int i;

  i = 0;
  while (i < arg->philo_num)
  {
    philo[i].last_eat_time = ft_get_time();
    if (pthread_create(&(philo[i].thread), NULL, ft_thread, &(philo[i])))
      return (1);
    i++;
  }
  ft_philo_check_finish(arg, philo);
  i = 0;
  while (i < arg->philo_num)
    pthread_join(philo[i++].thread, NULL);
  ft_free_thread(arg, philo);
  return (0);
}

int main(int argc, char **argv)
{
  t_arg arg;
  t_philo *philo;
  int errno;

  if (argc != 5 && argc != 6)              //argc는 무조건 5개 아니면 6개 이므로 에러처리
    return (print_error("error argc", 3)); //왜 3이지? 해결
  memset(&arg, 0, sizeof(t_arg));
  errno = ft_arg_init(&arg, argc, argv);
  if (errno)
    return (print_error("error arg init", errno));
  errno = ft_philo_init(&philo, &arg);
  if (errno)
    return (print_error("error philo init", errno));
  errno = ft_philo_start(&arg, philo);
  if (errno)
    return (print_error("error philo start", errno));
  return (0);
}
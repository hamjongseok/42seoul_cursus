/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 04:42:07 by jham              #+#    #+#             */
/*   Updated: 2022/08/02 05:22:09 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
  t_arg arg;
  t_philo *philo;
  int errno;

  if (argc != 5 && argc != 6)              //argc는 무조건 5개 아니면 6개 이므로 에러처리
    return (print_error("error argc", 3)); //왜 3이지?
  memset(&arg, 0, sizeof(t_arg));
  errno = ft_arg_init(&arg, argc, argv);

  return (0);
}
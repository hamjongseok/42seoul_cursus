/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 04:58:30 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/08/02 04:59:51 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int print_error(char *msg, int errno)
{
  printf("%s : %d\n", msg, errno);
  return (errno);
}
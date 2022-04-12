/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:12:04 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/04/12 16:16:49 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void free_str(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}
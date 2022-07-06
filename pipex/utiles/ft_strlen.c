/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:22:18 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/07/06 13:22:20 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t ft_strlen(const char *str)
{
    size_t length;

    length = 0;
    while (*str)
    {
        str++;
        length++;
    }
    return (length);
}
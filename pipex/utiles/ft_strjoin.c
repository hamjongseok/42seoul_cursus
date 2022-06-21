/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:59:04 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/21 16:06:02 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *new_mem;
    size_t s1_len;
    size_t s2_len;

    new_mem = NULL;
    if (s1 == NULL && s2 == NULL)
        exit_perror("ft_strjoin fail", 1);
    else if (s1 == NULL)
        return (ft_strdup(s2));
    else if (s2 == NULL)
        return (ft_strdup(s1));
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    new_mem = ft_calloc(1, s1_len + s2_len + 1);
    ft_strlcpy(new_mem, s1, s1_len + 1);
    ft_strlcpy(new_mem + s1_len, s2, s2_len + 1);
    return (new_mem);
}
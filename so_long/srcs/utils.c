/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:37:46 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/09 20:02:36 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char *ft_strdup_x_newline(char *s) //line, 새로운 문자열에 line내용을 다 넣어서 반환
{
    char *str;
    int size;
    int i;

    str = NULL;
    size = ft_strlen(s); //첫번째 줄에대한 사이즈를넣음
    i = 0;
    str = malloc(size + 1); //line의 사이즈 + 널값까지 할당
    if (!(str))
        return (NULL);
    while (s[i] && s[i] != '\n') //끝까지 돌리고, 개행을 만나기 전까지
    {
        str[i] = s[i]; //line의 문자를 하나씩 넣어준다.
        i++;
    }
    str[i] = '\0';
    return (str);
}

int ft_strcpy_x_newline(char *dst, char *src, int len)
{
    int src_len;
    int i;

    src_len = 0;
    i = 0;
    while (src[src_len])
        src_len++;
    if (len == 0)
        return (src_len);
    while (i < len - 1 && *src && *src != '\n')
    {
        *dst = *src;
        dst++;
        src++;
        i++;
    }
    *dst = '\0';
    return (src_len);
}

char *ft_strjoin_x_newline(char *s1, char *s2) //s1이 str, s2가 line
{
    char *str;
    size_t s1_len;
    size_t s2_len;

    str = NULL;
    if (s1 == NULL && s2 == NULL)
        return (NULL);
    else if (s1 == NULL)
        return (ft_strdup_without_newline(s2));
    else if (s2 == NULL)
        return (ft_strdup_without_newline(s1));
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    str = malloc(s1_len + s2_len);
    if (!(str))
        return (NULL);
    ft_strcpy_x_newline(str, s1, s1_len + 1);
    ft_strcpy_x_newline(str + s1_len, s2, s2_len + 1);
    free(s1);
    free(s2);
    return (str);
}
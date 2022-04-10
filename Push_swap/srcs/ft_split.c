/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:33:01 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/04/09 00:21:43 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
size_t ft_cntword(char const *s, char c) //av[i], ' '
{
    size_t cnt;

    cnt = 0;
    while (*s && *s == c) //av[i]가 널이 아니고, 그 값이 공백이라면 넘긴다. 문자를 찾기위함이지
        s++;
    while (*s) //위에서 공백을 넘겼으니 문자일때 들어온다.
    {
        if (*s && *s != c) //공백이 아닌 문자라면
        {
            cnt++;                //카운트를 세준다.
            while (*s && *s != c) //공백이 아니라면 ++로 값을 넘김 , 공백을 만날때까지
                s++;
        } //위의 이해가안되었던부분 문자인데 왜 ++하지? 였는데 "  23  7 "이렇게 23이 한번에 붙어있으면 이건 하나로 인식해야하기때문이다.
        while (*s && *s == c)
            s++;
    }
    return (cnt);
}

char *ft_fd_strdup(const char *s, size_t lenword) //arr[0]부터 들옴, 문자의길이
{
    char *arr;
    size_t idx;

    idx = 0;
    arr = (char *)malloc(sizeof(char) * (lenword + 1)); //arr 문장 만듬
    if (!arr)
        return (0);
    while (idx < lenword) // 문자 길이만큼 돌림
    {
        arr[idx] = s[idx];
        idx++;
    }
    arr[idx] = 0;
    return (arr);
}

size_t ft_lenword(char const *s, char c)
{
    size_t lenword;

    lenword = 0;
    while (*s && *s++ != c) //문자라면 세어준다.
        lenword++;
    return (lenword); //문자의 길이를 반환
}

void ft_free(char **s, int idx)
{
    while (idx--)
        free(s[idx]);
    free(s);
}

char **ft_split(char const *s, char c) //av[i], ' ' 이 들어온다
{
    char **arr;
    size_t cntword;
    size_t lenword;
    size_t aidx;

    cntword = ft_cntword(s, c);                                 //av[i]에서 잘라야할 cnt의 개수를 파악할수 있다.
    if (!(arr = (char **)malloc(sizeof(char *) * cntword + 1))) //split에 필요한 배열을 할당해준다
        return (0);
    aidx = 0;
    while (aidx < cntword) // 0부터 cnt개수 만큼 돌린다
    {
        while (*s && *s == c) //공백이면 넘겨준다 문자나올때까지
            s++;
        lenword = ft_lenword(s, c);           //문자의 길이 ex 123, 12 (값은 3, 2)
        arr[aidx] = ft_fd_strdup(s, lenword); //"1 2 3"이면 1을 arr[i]에다가 넣어서 만듬
        if (!arr[aidx])
        {
            ft_free(arr, aidx - 1);
            return (0);
        }
    }
}
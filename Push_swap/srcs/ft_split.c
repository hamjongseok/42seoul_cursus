/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham <jham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:33:01 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/05/18 11:35:35 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	ft_cntword(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s && *s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
			s++;
	}
	return (cnt);
}

char	*ft_fd_strdup(const char *s, size_t lenword)
{
	char	*arr;
	size_t	idx;

	idx = 0;
	arr = (char *)malloc(sizeof(char) * (lenword + 1));
	if (!arr)
		return (0);
	while (idx < lenword)
	{
		arr[idx] = s[idx];
		idx++;
	}
	arr[idx] = 0;
	return (arr);
}

size_t	ft_lenword(char const *s, char c)
{
	size_t	lenword;

	lenword = 0;
	while (*s && *s++ != c)
		lenword++;
	return (lenword);
}

void	ft_free(char **s, int idx)
{
	while (idx--)
		free(s[idx]);
	free(s);
	exit (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	cntword;
	size_t	lenword;
	size_t	aidx;

	cntword = ft_cntword(s, c);
	arr = (char **)malloc(sizeof(char *) * cntword + 1);
	if (!arr)
		return (0);
	aidx = 0;
	while (aidx < cntword)
	{
		while (*s && *s == c)
			s++;
		lenword = ft_lenword(s, c);
		arr[aidx] = ft_fd_strdup(s, lenword);
		if (!arr[aidx])
			ft_free(arr, aidx - 1);
		aidx++;
		s += lenword;
	}
	arr[cntword] = 0;
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:35:33 by hamjongseog       #+#    #+#             */
/*   Updated: 2021/12/09 01:59:50 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	sc;

	s1 = (unsigned char *)s;
	sc = (unsigned char)c;
	while (n--)
	{
		if (*s1 != sc)
			s1++;
		else
			return (s1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:19:08 by jham              #+#    #+#             */
/*   Updated: 2022/01/27 13:58:55 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

int ft_print_s(va_list *ap) //abc를 가리키는 ap 리스트가 들어옴
{
	int c;
	char *str;

	c = 0;
	str = (char *)va_arg(*ap, char *); //char * 크기만큼 값을 가져오고 그 크기만큼 이동, str에 넣음
	if (!str)
		return (write(1, "(null)", 6));
	while (*str) //str abc 쭈욱 끝까지 널까지
	{
		write(1, str, 1);
		str++;
		c++;
	}
	return (c);
}

int ft_setform(const char *fmt, va_list *ap) //x ,  26을 가르킴
{
	char c;

	c = 0;
	if (*fmt == '%')
		return (write(1, "%", 1));
	if (*fmt == 'c')
	{
		c = va_arg(*ap, int);
		write(1, &c, 1);
		return (1);
	}
	else if (*fmt == 's') //s라면  여기로들어옴
		return (ft_print_s(ap));
	else if (*fmt == 'd' || *fmt == 'i')
		return (ft_print_di(ap));
	else if (*fmt == 'u')
		return (ft_print_u(ap));
	else if (*fmt == 'x')
		return (ft_print_x(ap));
	else if (*fmt == 'X')
		return (ft_print_xx(ap));
	else if (*fmt == 'p')
		return (ft_print_p(ap));
	return (0);
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int result;

	if (fmt == NULL)
		return (-1);
	result = 0;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			result += ft_setform(fmt, &ap);
		}
		else
		{
			write(1, fmt, 1);
			result++;
		}
		fmt++;
	}
	va_end(ap);
	return (result);
}

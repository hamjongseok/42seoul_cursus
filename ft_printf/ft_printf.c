/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:19:08 by jham              #+#    #+#             */
/*   Updated: 2022/01/20 13:59:54 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
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

int ft_setform(const char *fmt, va_list *ap) //s의 주소값 ,  ap 들어옴
{
	char c;

	c = 0;
	if (*fmt == '%')
		return (write(1, "%", 1));
	if (*fmt == 'c')
	{
		c = va_arg(*ap, int);
		if (c == '\0')
			return (1);
		write(1, &c, 1);
		return (1);
	}
	else if (*fmt == 's') //s라면  여기로들어옴
		return (ft_print_s(ap));
	else if (*fmt == 'd' || *fmt == 'i')
		return (ft_print_di(ap));
	return (0);
}

int ft_printf(const char *fmt, ...) //%s , abc
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
			if (*fmt == 0)
				break;
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

int main(void)
{
	int mine;
	int real;

	mine = ft_printf("%d\n", 123);
	printf("\nmine=%d\n", mine);
	real = printf("%d", 123);
	printf("real=%d\n", real);
	return (0);
}
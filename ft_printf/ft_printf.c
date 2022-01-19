/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:19:08 by jham              #+#    #+#             */
/*   Updated: 2022/01/19 16:36:34 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_print_s(va_list ap) //abc를 가리키는 ap 리스트가 들어옴
{
	int c;
	char *str;

	c = 0;
	str = (char *)va_arg(ap, char *); //char * 크기만큼 값을 가져오고 그 크기만큼 이동, str에 넣음
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

int ft_setform(const char **fmt, va_list ap) //s의 주소값 ,  ap 들어옴
{
	int c;

	c = 0;
	if (**fmt == '%')
		return (write(1, "%", 1));
	while (**fmt) //s
	{
		if (**fmt == 'c')
		{
			c = va_arg(ap, int); //ap위치에 있는 정수의 값을 읽는다.그리고 c에다가 대입
			write(1, &c, 1);
			(*fmt)++;
			return (1);
		}
		else if (**fmt == 's') //s라면  여기로들어옴
		{
			return (ft_print_s(ap));
		}
	}
	return (0);
}

int ft_printf(const char *fmt, ...) //%s , abc
{
	va_list ap; //담을 가상 공간을 만들어줌
	int result; //반환값 저장
	int res;

	if (fmt == NULL)
		return (-1);
	result = 0;
	res = 0;
	va_start(ap, fmt);	 //ap에게 가변인자중 첫번째 인자의 주소를 알려줌 abc의 주소를 알려줌
	while (*fmt != '\0') //fmt를 널까지 돌리는데 %s
	{
		if (*fmt != '%') //만약 %이 아니라면 계속 출력한다.
		{
			write(1, fmt++, 1);
			result++; //반환 값이 출력하는 문자의 개수이기때문에 출력할때만 카운트를 높여주면된다.
		}
		else //%일 경우에 들어와서 해당으로 출력, 문자의 수 반환
		{
			fmt++;						// fmt가 s를 가르킴
			res = ft_setform(&fmt, ap); //일단 가변인수 ap와 %다음 문자를 넘겨준다. s의주소값 , ap를 넘김
			result += res;
			fmt++;
		}
	}
	va_end(ap);
	return (result);
}

int main(void)
{
	int res;
	int real;
	char a[10] = "abc";

	res = ft_printf("%c", '\0');
	printf("%d\n", res);

	real = printf("%c\n", '\0');
	printf("%d\n", real);
	return (0);
}

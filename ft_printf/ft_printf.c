/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jham <jham@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:19:08 by jham              #+#    #+#             */
/*   Updated: 2022/01/17 20:24:47 by jham             ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_setform() //뭐를 받아줘야할까 ? 가변인수를 이제 출력해주는것이니간 ...ap......?


int ft_printf(const char *fmt, ...)
{
	va_list	ap; //담을 가상 공간을 만들어줌 
	int		result; //반환값 저장
	int		res;
	
	if (fmt == NULL)
		return (-1);
	result = 0;
	va_start(ap, fmt); //ap에게 가변인자중 첫번째 인자의 주소를 알려줌	
	while (*fmt != '\0') //fmt를 널까지 돌리는데 
	{
		if (*fmt != '%') //만약 %이 아니라면 계속 출력한다. 
		{
			write(1, fmt++, 1);
			result++; //반환 값이 출력하는 문자의 개수이기때문에 출력할때만 카운트를 높여주면된다. 
		}
		else //%일 경우에 들어와서 해당으로 출력, 문자의 수 반환 
		{
			fmt++;
			res = ft_setform(); //일단 가변인수 ap와%다음 문자를 알려줘야 하니간 그걸 넘겨줘야한다. 

		}
	}
	va_end(ap);
	return (result);
}

int main(void)
{	
	int res;

	res = ft_printf("d2!13");
	printf("%d\n",res);
	return (0);
}

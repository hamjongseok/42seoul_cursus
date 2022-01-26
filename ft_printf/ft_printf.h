/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:24:59 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/01/26 11:49:27 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int ft_printf(const char *fmt, ...);
int ft_print_di(va_list *ap);
int ft_print_u(va_list *ap);
int ft_print_x(va_list *ap);
int ft_print_xx(va_list *ap);
char *ft_dectohex(size_t res);
static int hex_len(size_t res);
static size_t pow_hex(int n);
int ft_print_p(va_list *ap);

#endif

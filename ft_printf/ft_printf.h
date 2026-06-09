/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dobashihiromunin <dobashihiromunin@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:26:10 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/06/09 17:37:28 by dobashihiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_printf(const char *format, ...);
int ft_putchar(char c);
int ft_putstr(char *s);
int	ft_putnbr(int nb);
int ft_put_hexlow(unsigned long long n);
int ft_put_hexup(unsigned long long n);
int print_check(char spec,va_list *args);
int	ft_putnbr_unsigned(unsigned int nb);
int ft_putptr(void *ptr);
int hexlen(unsigned long long n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:31:02 by hdobashi          #+#    #+#             */
/*   Updated: 2026/08/19 17:51:51 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		temp;

	count = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
			temp = print_check(format[++i], &args);
		else if (format[i] == '%')
			temp = -1;
		else
			temp = ft_putchar(format[i]);
		if (temp == -1)
		{
			count = -1;
			break ;
		}
		count = count + temp;
	}
	va_end(args);
	return (count);
}

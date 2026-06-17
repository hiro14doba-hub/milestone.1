/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:03:24 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/06/17 16:32:47 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_check(char spec, va_list *args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count = ft_putchar(va_arg(*args, int));
	else if (spec == 's')
		count = ft_putstr(va_arg(*args, char *));
	else if (spec == 'x')
		count = ft_put_hexlow(va_arg(*args, unsigned int));
	else if (spec == 'X')
		count = ft_put_hexup(va_arg(*args, unsigned int));
	else if (spec == 'd' || spec == 'i')
		count = ft_putnbr(va_arg(*args, int));
	else if (spec == 'u')
		count = ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (spec == 'p')
		count = ft_putptr(va_arg(*args, void *));
	else if (spec == '%')
		count = ft_putchar('%');
	return (count);
}

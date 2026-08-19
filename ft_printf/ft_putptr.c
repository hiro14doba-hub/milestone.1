/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:14:42 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/08/19 16:42:23 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					count;
	int					temp;

	temp = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	addr = (unsigned long long)ptr;
	temp = ft_putstr("0x");
	if (temp == -1)
		return (-1);
	count = count + temp;
	temp = ft_put_hexlow(addr);
	if (temp == -1)
		return (-1);
	count = count + temp;
	return (count);
}

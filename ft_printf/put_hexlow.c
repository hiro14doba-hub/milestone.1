/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexlow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:41:23 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/08/19 17:42:30 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexlow(unsigned long long n)
{
	int	count;
	int	temp;

	count = 0;
	if (n >= 16)
	{
		temp = ft_put_hexlow(n / 16);
		if (temp == -1)
			return (-1);
		count = count + temp;
	}
	temp = ft_putchar("0123456789abcdef"[n % 16]);
	if (temp == -1)
		return (-1);
	return (count + temp);
}

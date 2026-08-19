/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:48:47 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/08/19 17:42:32 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexup(unsigned long long n)
{
	int	count;
	int	temp;

	count = 0;
	if (n >= 16)
	{
		temp = ft_put_hexup(n / 16);
		if (temp == -1)
			return (-1);
		count = count + temp;
	}
	temp = ft_putchar("0123456789ABCDEF"[n % 16]);
	if (temp == -1)
		return (-1);
	return (count + temp);
}

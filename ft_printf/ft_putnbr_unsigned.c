/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:09:06 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/08/19 17:42:05 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	int		len;
	long	nptr;
	int		temp;

	len = 0;
	nptr = nb;
	if (nptr >= 10)
	{
		temp = ft_putnbr_unsigned(nptr / 10);
		if (temp == -1)
			return (-1);
		len = len + temp;
	}
	temp = ft_putchar(nptr % 10 + '0');
	if (temp == -1)
		return (-1);
	return (len + temp);
}

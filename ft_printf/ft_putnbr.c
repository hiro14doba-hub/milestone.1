/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:35:36 by hdobashi          #+#    #+#             */
/*   Updated: 2026/08/19 17:41:11 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		len;
	long	nptr;
	int		temp;

	len = 0;
	nptr = nb;
	if (nptr < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		nptr = nptr * -1;
	}
	if (nptr >= 10)
	{
		temp = ft_putnbr(nptr / 10);
		if (temp == -1)
			return (-1);
		len = len + temp;
	}
	temp = ft_putchar(nptr % 10 + '0');
	if (temp == -1)
		return (-1);
	return (len + temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:09:06 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/06/17 16:32:26 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	int		len;
	char	c;
	long	nptr;

	nptr = nb;
	len = 0;
	if (nptr >= 10)
		len = len + ft_putnbr(nptr / 10);
	c = nptr % 10 + '0';
	len = len + ft_putchar(c);
	return (len);
}

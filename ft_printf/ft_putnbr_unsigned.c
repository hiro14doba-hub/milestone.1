/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dobashihiromunin <dobashihiromunin@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:09:06 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/06/09 17:40:08 by dobashihiro      ###   ########.fr       */
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
		len = len + ft_putnbr(nptr/10);
	c = nptr % 10 + '0';
	len = len + ft_putchar(c);
	return (len);
}
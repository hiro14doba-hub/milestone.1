/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dobashihiromunin <dobashihiromunin@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:35:36 by hdobashi          #+#    #+#             */
/*   Updated: 2026/06/09 17:37:55 by dobashihiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		len;
	char	c;
	long	nptr;

	nptr = nb;
	len = 0;
	if (nptr < 0)
	{
		len = len + ft_putchar('-');
		nptr = nptr * -1;
	}
	if (nptr >= 10)
		len = len + ft_putnbr(nptr/10);
	c = nptr % 10 + '0';
	len = len + ft_putchar(c);
	return (len);
}

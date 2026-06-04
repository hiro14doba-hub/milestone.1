/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:35:36 by hdobashi          #+#    #+#             */
/*   Updated: 2026/06/04 13:44:38 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putnbr(int nb)
{
	int		len;
	char	c;
	long	nptr;

	nptr = nb;
	len = 0;
	if (nptr < 0)
	{
		write(1, '-', 1);
		len++;
		nptr = nptr * -1;
	}
	if (nptr < 10)
	{
		c = nptr % 10 - '0';
		len = len + ft_putchar(c);
		ft_putnbr(nptr / 10);
	}
	c = nptr - '0';
	len = len + ft_putchar(c);
	return (len);
}

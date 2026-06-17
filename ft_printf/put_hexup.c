/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:48:47 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/06/17 16:32:58 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexup(unsigned long long n)
{
	char	*res;
	int		len;
	int		count;

	len = hexlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		len--;
		res[len] = "0123456789ABCDEF"[n % 16];
		n = n / 16;
	}
	count = ft_putstr(res);
	free(res);
	return (count);
}

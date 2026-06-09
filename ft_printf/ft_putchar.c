/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dobashihiromunin <dobashihiromunin@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:26:13 by hdobashi          #+#    #+#             */
/*   Updated: 2026/06/09 17:38:27 by dobashihiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	len;

	len = 0;
	write(1, &c, 1);
	len = len + 1;
	return (len);
}

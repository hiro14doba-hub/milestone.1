/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dobashihiromunin <dobashihiromunin@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:26:06 by hdobashi          #+#    #+#             */
/*   Updated: 2026/06/09 17:38:05 by dobashihiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if(!s)
		return(ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		len = len + ft_putchar(s[i]);
		i++;
	}
	return (len);
}

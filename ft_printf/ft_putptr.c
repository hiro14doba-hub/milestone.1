/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dobashihiromunin <dobashihiromunin@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:14:42 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/06/09 17:37:59 by dobashihiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putptr(void *ptr)
{
    unsigned long long addr;
    int count;
    
    if(!ptr)
        return(ft_putstr("(nil)"));
    count = 0;
    addr = (unsigned long long)ptr;

    count = count + ft_putstr("0x");
    count = count + ft_put_hexlow(addr);
    return(count);
}

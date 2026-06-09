/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexlow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dobashihiromunin <dobashihiromunin@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:41:23 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/06/09 17:38:15 by dobashihiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int hexlen(unsigned long long n)
{
    int len;

    len=0;
    if(n == 0)
        return(1);
    while(n > 0)
    {
        n = n/16;
        len++;
    }
    return(len);
}

int ft_put_hexlow(unsigned long long n)
{
    char *res;
    int len;
    int count;

    len = hexlen(n);
    res = (char *)malloc(sizeof(char)*(len + 1));
    if(!res)
        return(0);
    res[len]= '\0';
    if(n == 0)
        res[0]='0';
    while(n > 0)
    {
        len--;
        res[len] = "0123456789abcdef"[n % 16];
        n = n/16;
    }
    count = ft_putstr(res);
    free(res);
    return(count);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dobashihiromunin <dobashihiromunin@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:23:01 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/06/17 12:51:45 by dobashihiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin(char *s1,char *s2)
{
    int i;
    int j;

    i= 0;
    j=0;

    while(s1[i] != '\0')
        i++;
    while(s2[j] !='\0')
    {
        s1[i+j] = s2[j];
        j++;
    }
    s1[i+j] = '\0';
    free(s2);
    return(s1);
}

int check_line(char *s)
{
    int i;
    i=0;

    while(s[i] !='\0')
    {
        if(s[i] == '\n')
            return(1);
        i++;
    }
    return(0);
}


int ft_strlen(char *s)
{
    int i;
    i = 0;

    while(s[i] !='\0')
        i++;
    return(i);
}


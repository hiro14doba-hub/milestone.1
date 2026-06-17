/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:33:47 by hdobashi          #+#    #+#             */
/*   Updated: 2026/06/17 19:35:59 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
static char	*reed_store(int fd, char *store);

int			ft_strlen(char *s);
int			check_line(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*update_store(char *s);
char		*get_line(char *s);

#endif
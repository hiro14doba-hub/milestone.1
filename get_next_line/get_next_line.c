/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:23:07 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/07/29 17:26:55 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_store(int fd, char *store)
{
	char	*buf;
	int		bytes;

	if (check_line(store))
		return (store);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(store);
			store = NULL;
		}
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		store = ft_strjoin(store, buf);
		if (check_line(buf))
			break ;
	}
	free(buf);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_store(fd, store);
	if (!store)
		return (NULL);
	line = get_line(store);
	store = update_store(store);
	return (line);
}

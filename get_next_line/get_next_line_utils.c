/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:23:01 by dobashihiro       #+#    #+#             */
/*   Updated: 2026/08/09 20:53:06 by hdobashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*new;
// 	int		i;
// 	int		j;

// 	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!new)
// 	{
// 		free(s1);
// 		return (NULL);
// 	}
// 	i = -1;
// 	if (s1)
// 		while (s1[++i])
// 			new[i] = s1[i];
// 	else
// 		i = 0;
// 	j = -1;
// 	while (s2[++j])
// 		new[i + j] = s2[j];
// 	new[i + j] = '\0';
// 	free(s1);
// 	return (new);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (s1 && s1[i])
		i++;
	j = 0;
	while (s2 && s2[j])
		j++;
	new = (char *)malloc(sizeof(char) * i + j + 1);
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	new[i + j] = '\0';
	while (j--)
		new[i + j] = s2[j];
	while (i--)
		new[i] = s1[i];
	free(s1);
	return (new);
}

int	check_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (!s || !s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_store(char *s)
{
	int		i;
	int		j;
	char	*store;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (!s || !s[i])
	{
		free(s);
		return (NULL);
	}
	store = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!store)
	{
		free(s);
		return (NULL);
	}
	i++;
	j = 0;
	while (s[i])
		store[j++] = s[i++];
	store[j] = '\0';
	free(s);
	return (store);
}

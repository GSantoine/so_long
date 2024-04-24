/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:14:28 by agras             #+#    #+#             */
/*   Updated: 2024/04/08 11:18:24 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
#include "../libft.h"

char	*cut_buff(char **left, int i)
{
	char	*line;
	char	*tmp;

	line = ft_strndup(*left, i - 1);
	tmp = (*left);
	(*left) += i;
	*left = ft_strndup(*left, BUFFER_SIZE);
	free(tmp);
	return (line);
}

char	*exit_func(char **left, char *buf)
{
	char	*tmp;

	tmp = NULL;
	if (*left)
	{
		if ((*left)[0])
			tmp = ft_strndup(*left, ft_strlen(*left));
	}
	free(*left);
	free(buf);
	*left = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*left = NULL;
	char			*buf;
	int				i;
	int				bytes_read;

	i = 0;
	if (left)
	{
		while (left[i])
		{
			if (left[i] == '\n')
				return (cut_buff(&left, i + 1));
			i++;
		}
	}
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (exit_func(&left, buf));
	buf[bytes_read] = '\0';
	left = ft_strjoin(left, buf);
	return (get_next_line(fd));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:08:18 by agras             #+#    #+#             */
/*   Updated: 2021/12/29 20:31:48 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *str, int n)
{
	char	*dup;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	while (str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strcpy_to_end(char	*dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (&(dest[i]));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dup;
	char	*dup_start;

	dup = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dup)
		return (NULL);
	dup_start = dup;
	if (s1)
	{
		dup = ft_strcpy_to_end(dup, s1);
		free(s1);
	}
	if (s2)
	{
		dup = ft_strcpy_to_end(dup, s2);
		free(s2);
	}
	*dup = '\0';
	return (dup_start);
}

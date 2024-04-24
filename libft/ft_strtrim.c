/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:09:03 by antoine           #+#    #+#             */
/*   Updated: 2021/12/08 16:58:01 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strndup(const char *str, int n)
{
	char	*dup;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (str[len] && len < n)
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (++i < len)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (is_in_set(*s1, set) == 0)
			break ;
		s1++;
	}
	len = ft_strlen(s1) - 1;
	while (len > 0)
	{
		if (is_in_set(s1[len], set) == 0)
			break ;
		len--;
	}
	return (ft_strndup(s1, len + 1));
}

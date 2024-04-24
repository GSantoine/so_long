/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:14:48 by agras             #+#    #+#             */
/*   Updated: 2021/12/10 17:22:59 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_separator(char c, char sep)
{
	if (sep == c)
		return (1);
	return (0);
}

int	cpy_word(const char *s1, char *s2, char c)
{
	int	i;

	i = 0;
	while (s1[i] && is_separator(s1[i], c) == 0)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (i);
}

int	get_word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && is_separator(s[i], c) == 0)
		i++;
	return (i);
}

int	count_words(const char *s, char c)
{
	int	flick;
	int	word_count;

	flick = 0;
	word_count = 0;
	while (*s)
	{
		if (is_separator(*s, c) == 0 && flick == 0)
		{
			word_count++;
			flick = 1;
		}
		if (is_separator(*s, c) == 1)
			flick = 0;
		s++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	tab = NULL;
	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (*s)
	{
		if (is_separator(*s, c) == 0)
		{
			tab[i] = malloc(sizeof(char) * (get_word_len(s, c) + 1));
			if (tab[i] == NULL)
				return (NULL);
			s += cpy_word(s, tab[i], c);
			i++;
		}
		while (*s && is_separator(*s, c) == 1)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}

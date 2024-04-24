/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:29:43 by agras             #+#    #+#             */
/*   Updated: 2021/12/08 11:41:38 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	max;

	j = 0;
	max = ft_strlen(little);
	if (*little == 0)
		return ((char *)big);
	while (big[j] && j < len)
	{
		i = 0;
		while (big[j + i] == little[i] && (j + i) < len && big[j + i])
		{
			if (i + 1 >= max)
				return ((char *)&(big[j]));
			i++;
		}
		j++;
	}
	return (NULL);
}

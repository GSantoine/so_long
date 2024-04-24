/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:16:02 by agras             #+#    #+#             */
/*   Updated: 2021/12/04 21:08:59 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		balance;

	i = 0;
	balance = 0;
	while (i < n)
	{
		balance = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (balance != 0)
			return (balance);
		i++;
	}
	return (0);
}

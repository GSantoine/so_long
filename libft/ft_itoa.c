/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:39:35 by agras             #+#    #+#             */
/*   Updated: 2021/12/10 16:52:47 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	get_nb_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	cpy_nb_in_array(long n, char *arr, int len)
{
	while (len >= 0)
	{
		arr[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	long	nb;
	int		len;

	nb = n;
	is_neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		is_neg = 1;
	}
	len = get_nb_len(nb);
	str = malloc(sizeof(char) * (len + is_neg + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	cpy_nb_in_array(nb, str + is_neg, len - 1);
	str[len + is_neg] = '\0';
	return (str);
}

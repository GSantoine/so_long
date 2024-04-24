/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:17:26 by agras             #+#    #+#             */
/*   Updated: 2021/12/17 14:24:37 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	dst_len;
	size_t	src_len;
	size_t	s_len;

	d_len = 0;
	s_len = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (dst[d_len] != 0 && d_len < dstsize)
		d_len++;
	while (s_len + 1 < dstsize - d_len && src[s_len])
	{
		dst[dst_len + s_len] = src[s_len];
		s_len++;
	}
	dst[dst_len + s_len] = '\0';
	return (d_len + src_len);
}

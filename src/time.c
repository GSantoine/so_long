/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:19:18 by agras             #+#    #+#             */
/*   Updated: 2022/02/09 15:56:14 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_time(clock_t *clock_start, long duration_milli)
{
	clock_t	check;

	check = clock();
	if ((check - *clock_start) * 1000 / CLOCKS_PER_SEC >= duration_milli)
	{
		*clock_start = clock();
		return (1);
	}
	return (0);
}

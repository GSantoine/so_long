/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:31:09 by agras             #+#    #+#             */
/*   Updated: 2022/02/23 20:01:37 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_coords(t_var *var, int y, int x, int *p_count)
{
	if (var->map[y][x] == 'P')
	{
		var->player.y = y;
		var->player.x = x;
		*p_count += 1;
	}
}

void	init_game(t_var *var, int y, int x)
{
	var->win_width = x * TILE_YSIZE;
	var->win_height = y * TILE_XSIZE;
}

int	init_player(t_var *var)
{
	int	y;
	int	x;
	int	p_count;

	p_count = 0;
	var->player.to_collect_total = 0;
	var->player.collected = 0;
	var->player.moves_count = 0;
	y = 0;
	while (var->map[y])
	{
		x = 0;
		while (var->map[y][x])
		{
			init_coords(var, y, x, &p_count);
			if (var->map[y][x] == 'C')
				var->player.to_collect_total += 1;
			x++;
		}
		y++;
	}
	if (p_count != 1)
		return (return_error_msg(ERR_PLAYER, -1));
	init_game(var, y, x);
	return (0);
}

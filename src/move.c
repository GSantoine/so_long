/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:10:37 by agras             #+#    #+#             */
/*   Updated: 2022/02/23 20:10:50 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_player_moves(int moves_count)
{
	char	*count;

	count = ft_itoa(moves_count);
	ft_putstr_fd("Player move count = ", 1);
	ft_putstr_fd(count, 1);
	ft_putchar_fd('\n', 1);
	free(count);
}

void	move_player(t_var *var, int move_y, int move_x)
{
	// if (var->prev_cell.symbol == 'E')
	// 	var->map[var->player.y][var->player.x] = 'E';
	// else
	var->map[var->player.y][var->player.x] = '0';
	var->player.y += move_y;
	var->player.x += move_x;
	var->prev_cell.y = var->player.y;
	var->prev_cell.x = var->player.x;
	var->player.moves_count += 1;
	print_player_moves(var->player.moves_count);
	// var->prev_cell.symbol = var->map[var->player.y][var->player.x];
}

int	test_move_player(t_var *var, int move_y, int move_x)
{
	if (var->map[var->player.y + move_y][var->player.x + move_x] == '1')
		return (0);
	if (var->map[var->player.y + move_y][var->player.x + move_x] == 'E'
		&& var->player.collected != var->player.to_collect_total)
		return (0);
	move_player(var, move_y, move_x);
	if (var->map[var->player.y][var->player.x] == 'C')
		var->player.collected += 1;
	if (var->map[var->player.y][var->player.x] == 'E')
	{
		if (var->player.collected == var->player.to_collect_total)
		{
			var->map[var->player.y][var->player.x] = 'P';
			exit_success(var);
		}
	}
	var->map[var->player.y][var->player.x] = 'P';
	draw_map(var);
	return (0);
}

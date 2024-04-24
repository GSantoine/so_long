/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:54:57 by agras             #+#    #+#             */
/*   Updated: 2022/02/23 20:06:36 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_player_input(int keycode, t_var *var)
{
	if (keycode == 65307 && var->map)
		exit_success(var);
	if (keycode == 119)
	{
		test_move_player(var, -1, 0);
	}
	if (keycode == 115)
	{
		test_move_player(var, 1, 0);
	}
	if (keycode == 97)
	{
		test_move_player(var, 0, -1);
	}
	if (keycode == 100)
	{
		test_move_player(var, 0, 1);
	}
	return (0);
}

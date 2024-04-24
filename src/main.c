/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:27:29 by agras             #+#    #+#             */
/*   Updated: 2024/04/08 11:25:22 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_loop(t_var *var)
{
	var->mlx = mlx_init();
	if (!var->mlx)
		return (-1);
	var->win = mlx_new_window(var->mlx,
			var->win_width, var->win_height, "so_long");
	if (!var->win)
		return (-1);
	init_textures(var);
	mlx_key_hook(var->win, get_player_input, var);
	mlx_hook(var->win, 17, 0L, exit_success, var);
	mlx_loop_hook(var->mlx, draw_map, var);
	draw_map(var);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	var;

	if (ac != 2)
  {
    ft_putstr_fd("usage: ./so_long map.ber\n", 1);
    return (1);
  }
	if (strcmp(ft_strrchr(&(av[1][1]), '.'), ".ber") != 0)
	{
		ft_putstr_fd("not a map !\n", 1);
		return (1);
	}
	var.map = get_file_content_2d(av[1]);
	if (!var.map)
		return (1);
	if (!check_map_valide(var.map))
		return (1);
	if (init_player(&var) == -1)
		return (1);
	if (init_loop(&var) == -1)
		return (1);
	mlx_loop(var.mlx);
	exit_success(&var);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:08:41 by agras             #+#    #+#             */
/*   Updated: 2022/02/23 16:24:07 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_success(t_var *var)
{
	free_2d_tab((void **)var->map);
	clear_alltextures(var, var->textures);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	exit(0);
}

int	exit_error(t_var *var)
{
	free_2d_tab((void **)var->map);
	if (var->textures)
		clear_alltextures(var, var->textures);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	exit(-1);
}

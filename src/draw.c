/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:13:49 by agras             #+#    #+#             */
/*   Updated: 2022/02/10 14:24:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_frame(t_var *var, t_texture *texture, int y_pixels, int x_pixels)
{
	mlx_put_image_to_window(var->mlx, var->win,
		texture->img[texture->frame].img, x_pixels, y_pixels);
	if (check_time(&(texture->clock_start), texture->frame_update_time))
	{
		texture->frame = texture->frame + 1;
		if (texture->frame >= texture->total_frames)
			texture->frame = 0;
	}
}

void	draw_texture(t_var *var, t_texture *textures, char cell_char, int y_pixels, int x_pixels)
{
	while (textures)
	{
		if (textures->symbol == cell_char)
			draw_frame(var, textures, y_pixels, x_pixels);
		textures = textures->next;
	}
}

int	draw_map(t_var *var)
{
	int	y;
	int	x;

	y = 0;
	while (var->map[y])
	{
		x = 0;
		while (var->map[y][x])
		{
			draw_texture(var, var->textures, var->map[y][x], y * TILE_YSIZE, x * TILE_XSIZE);
			x++;
		}
		y++;
	}
	return (1);
}

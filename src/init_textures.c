/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:25:33 by agras             #+#    #+#             */
/*   Updated: 2022/02/23 16:45:23 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_texture	*gen_new_texture(t_img *texture, char symbol,
	int total_frames, int update_time)
{
	t_texture	*new;

	new = malloc(sizeof(t_texture));
	if (!new)
		return (NULL);
	if (!texture)
		return (NULL);
	new->img = texture;
	new->symbol = symbol;
	new->frame = 0;
	new->total_frames = total_frames;
	new->frame_update_time = update_time;
	new->clock_start = clock();
	new->next = NULL;
	return (new);
}

t_img	load_texture(t_var *var, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(var->mlx, path, &img.width, &img.height);
	if (!img.img)
	{
		ft_putstr_fd("Unable to load texture\n", 1);
		exit_error(var);
	}
	return (img);
}

char	*get_path_to_img(t_var *var, char *path_to, char *index)
{
	char	*frame_path;
	char	*final_path;

	frame_path = ft_strcat_malloc(path_to, index);
	if (!frame_path)
		exit_error(var);
	final_path = ft_strcat_malloc(frame_path, ".xpm");
	if (!final_path)
		exit_error(var);
	free(frame_path);
	return (final_path);
}

t_img	*load_animation(t_var *var, char *path_to, int total_frames)
{
	int		i;
	char	*index;
	char	*path;
	t_img	*imgs;

	imgs = malloc(sizeof(t_img) * 200);
	if (!imgs)
		return (NULL);
	i = 0;
	while (i < 200)
	{
		index = ft_itoa(i);
		if (index)
		{
			path = get_path_to_img(var, path_to, index);
		}
		imgs[i] = load_texture(var, path);
		free(path);
		free(index);
		if (!imgs[i].img || i + 1 >= total_frames)
			break ;
		i++;
	}
	return (imgs);
}

void	init_textures(t_var *var)
{
	var->textures = NULL;
	add_new_texture(&var->textures, gen_new_texture(load_animation
			(var, "resources/empty", 1), '0', 1, 0));
	add_new_texture(&var->textures, gen_new_texture(load_animation
			(var, "resources/box", 1), '1', 1, 0));
	add_new_texture(&var->textures, gen_new_texture(load_animation
			(var, "resources/bob", 1), 'P', 1, 0));
	add_new_texture(&var->textures, gen_new_texture(load_animation
			(var, "resources/exit", 1), 'E', 1, 0));
	add_new_texture(&var->textures, gen_new_texture(load_animation
			(var, "resources/coin", 2), 'C', 2, 1000));
}

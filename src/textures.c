/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:03:50 by agras             #+#    #+#             */
/*   Updated: 2022/02/23 16:18:05 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_new_texture(t_texture **textures, t_texture *new)
{
	if (!new)
		return ;
	if (!textures)
	{
		(*textures) = new;
		return ;
	}
	new->next = (*textures);
	(*textures) = new;
}

void	del_texture(t_var *var, t_texture **texture)
{
	int			i;

	i = 0;
	if (!*texture)
		return ;
	while (i < (*texture)->total_frames)
	{
		mlx_destroy_image(var->mlx, (*texture)->img[i].img);
		i++;
	}
	free((*texture)->img);
	free(*texture);
}

void	clear_alltextures(t_var *var, t_texture *texture)
{
	// t_texture	*prev;
	t_texture	*next;

	// prev = NULL;
	while (texture)
	{
		next = texture->next;
		// prev = texture;
		del_texture(var, &texture);
		texture = next;
	}
}

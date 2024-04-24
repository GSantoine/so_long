/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:30:56 by agras             #+#    #+#             */
/*   Updated: 2024/03/28 01:32:51 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"
# include "time.h"
# include "string.h"

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define TILE_YSIZE 32
# define TILE_XSIZE 32
# define ERR_MISSING "The map must contain 1 exit, 1 start and > 1 collectible\n"
# define ERR_SHAPE "The map must be rectangular\n"
# define ERR_WALL "The map must be surrounded by walls\n"
# define ERR_PLAYER "The map cannot have more than 1 player\n"

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}			t_img;

typedef struct s_texture
{
	t_img				*img;
	char				symbol;
	int					frame;
	int					total_frames;
	int					frame_update_time;
	clock_t				clock_start;
	struct s_texture	*next;
}			t_texture;

typedef struct s_map_max {
	int	y;
	int	x;
}			t_max;

typedef struct s_check_map {
	char	*to_find;
	char	*found;
	int		i;
}			t_check;

typedef struct s_cell {
	int		x;
	int		y;
	char	symbol;
}			t_cell;

typedef struct s_player {
	int	y;
	int	x;
	int	collected;
	int	to_collect_total;
	int	moves_count;
}			t_player;

typedef struct s_var {
	void		*mlx;
	void		*win;
	char		**map;
	t_cell		prev_cell;
	t_player	player;
	t_texture	*textures;
	int			win_width;
	int			win_height;
}			t_var;

# define BUFFER_SIZE 1000000

char	**get_file_content_2d(char *path);
int		check_map_valide(char **map);
int		get_player_input(int keycode, t_var *var);
int		close_win(t_var *var);
int		init_player(t_var *var);
int		test_move_player(t_var *var, int move_y, int move_x);
void	init_textures(t_var *var);
int		draw_map(t_var *var);
int		check_time(clock_t *clock_start, long duration_milli);
int		exit_success(t_var *var);
int		exit_error(t_var *var);
void	add_new_texture(t_texture **textures, t_texture *new);
void	del_texture(t_var *var, t_texture **texture);
void	clear_alltextures(t_var *var, t_texture *texture);
int		return_error_msg(char *msg, int ret);

#endif

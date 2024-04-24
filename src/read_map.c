/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:29:10 by agras             #+#    #+#             */
/*   Updated: 2024/04/08 11:34:12 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// not safe in case of len > strlen(str), for it to be safe use this function
// after checking len is not greater than str's length

// char	*ft_strndup(char *str, int len)
// {
// 	int		i;
// 	char	*dup;

// 	if (!str || len < 0)
// 		return (NULL);
// 	i = 0;
// 	dup = malloc(sizeof(char) * (len + 1));
// 	if (!dup)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		dup[i] = str[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }

int	return_error_msg(char *msg, int ret)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	return (ret);
}

int	get_max_y(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y - 1);
}

int	get_max_x(char *line)
{
	int	x;

	x = 0;
	while (line[x])
		x++;
	return (x - 1);
}

int	fill_str(char **str, char *str_literal)
{
	int	i;

	if (!str)
		return (-1);
	if (!*str)
		return (-1);
	i = 0;
	while (str_literal[i])
	{
		*str[i] = str_literal[i];
		i++;
	}
	*str[i] = '\0';
	return (0);
}

int	check_line_is_valide(char *line, int y, t_max max, t_check *check)
{
	int		x;

	x = 0;
	while (line[x])
	{
		if (y == 0 || y == max.y || x == 0 || x == max.x)
		{
			if (line[x] != '1')
				return (return_error_msg(ERR_WALL, 0));
		}
		if (ft_strchr(check->to_find, line[x])
			&& !ft_strchr(check->found, line[x]))
		{
			check->found[check->i] = line[x];
			check->i += 1;
		}
		x++;
	}
	if (x - 1 != max.x)
		return (return_error_msg(ERR_SHAPE, 0));
	return (1);
}

void	free_check(t_check check)
{
	free(check.found);
	free(check.to_find);
}

int	check_map_valide(char **map)
{
	int		y;
	t_max	max;
	t_check	check;

	y = 0;
	max.y = get_max_y(map);
	max.x = get_max_x(*map);
	check.to_find = ft_strdup("01CEP");
	check.found = ft_calloc(6, 1);
	if (!check.to_find || !check.found)
		return (-1);
	check.i = 0;
	while (map[y])
	{
		if (!check_line_is_valide(map[y], y, max, &check))
			return (0);
		y++;
	}
	for (char* c = check.found; *c; c++) {
    if (ft_strchr(check.to_find, *c) != NULL)
    {
      free_check(check);
      return (1);
    }
  }
  free_check(check);
  return (return_error_msg(ERR_MISSING, 0));
}

char	**get_file_content_2d(char *path)
{
	int		fd;
	char	**map;
	int		y;

	y = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * 100000);
	while (1)
	{
		map[y] = get_next_line(fd);
		if (!map[y])
			break ;
		y++;
	}
	return (map);
}

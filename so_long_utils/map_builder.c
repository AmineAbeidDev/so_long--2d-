/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:52:04 by aabeid            #+#    #+#             */
/*   Updated: 2021/12/18 18:47:01 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	texture_manager(t_mlx x_y, t_mlx *img, t_mlx mlx, char **map)
{
	if (map[x_y.x][x_y.y] == '1')
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
			(*img).img1, (*img).x, (*img).y);
	if (map[x_y.x][x_y.y] != '1')
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
			(*img).img2, (*img).x, (*img).y);
	if (map[x_y.x][x_y.y] == 'E')
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
			(*img).img3, (*img).x, (*img).y);
	if (map[x_y.x][x_y.y] == 'C')
	{
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
			(*img).img4, (*img).x, (*img).y);
		img->collect += 1;
	}
	if (map[x_y.x][x_y.y] == 'P')
	{
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
			(*img).img5, (*img).x, (*img).y);
		(*img).px = x_y.x;
		(*img).py = x_y.y;
	}
}

t_mlx	*mlx_to_img(t_mlx mlx)
{
	t_mlx	*img;
	int		param;

	img = malloc(sizeof(t_mlx));
	(*img).img1 = mlx_xpm_file_to_image(mlx.mlx_ptr,
			"objs/wall.xpm", &param, &param);
	(*img).img2 = mlx_xpm_file_to_image(mlx.mlx_ptr,
			"objs/floor.xpm", &param, &param);
	(*img).img3 = mlx_xpm_file_to_image(mlx.mlx_ptr,
			"objs/exit.xpm", &param, &param);
	(*img).img4 = mlx_xpm_file_to_image(mlx.mlx_ptr,
			"objs/collect.xpm", &param, &param);
	(*img).img5 = mlx_xpm_file_to_image(mlx.mlx_ptr,
			"objs/player.xpm", &param, &param);
	(*img).x = 0;
	(*img).y = 0;
	return (img);
}

t_mlx	*map_builder(char **map, t_mlx mlx, int height, int width)
{
	t_mlx	*img;
	t_mlx	x_y;
	t_mlx	*ret;

	img = mlx_to_img(mlx);
	x_y.x = 0;
	x_y.y = 0;
	img->collect = 0;
	while (x_y.x < height)
	{
		while (x_y.y < width)
		{
			texture_manager(x_y, img, mlx, map);
			(*img).x += 50;
			x_y.y++;
		}
		x_y.y = 0;
		(*img).x = 0;
		(*img).y += 50;
		x_y.x++;
	}
	img->map = map;
	ret = img;
	free(img);
	return (ret);
}

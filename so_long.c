/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:12:33 by aabeid            #+#    #+#             */
/*   Updated: 2022/10/06 12:21:29 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cursur(void)
{
	exit(0);
}

int	keys(int keycode, t_mlx *mlx)
{
	mlx->x = mlx->px;
	mlx->y = mlx->py;
	if (keycode == 126 || keycode == 13)
		move_up(mlx);
	else if (keycode == 125 || keycode == 1)
		move_down(mlx);
	else if (keycode == 124 || keycode == 2)
		move_right(mlx);
	else if (keycode == 123 || keycode == 0)
		move_left(mlx);
	else if (keycode == 53)
	{
		ft_free(mlx->map);
		exit(0);
	}
	if (mlx->collect == 0)
	{
		if (mlx -> map[mlx->px][mlx->py] == 'E')
		{
			ft_free(mlx->map);
			exit(0);
		}
	}
	return (1);
}

t_mlx	*pre_build(char **map, t_mlx mlx)
{
	t_mlx	*utils;
	int		height;
	int		width;

	height = 0;
	width = ft_strlen(map[0]);
	while (map[height] != NULL)
		height++;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, width * 50, height * 50,
			"so_long");
	utils = map_builder(map, mlx, height, width);
	utils->win_ptr = mlx.win_ptr;
	utils->mlx_ptr = mlx.mlx_ptr;
	return (utils);
}

void	so_long(char *map_path)
{
	t_mlx	mlx;
	t_mlx	utils;
	char	**map;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1 || ft_strnstr(map_path, ".ber", 4) == 0)
	{
		printf("Error\nfile/path not valide\n");
		exit(1);
	}
	map = map_checker(map_path);
	mlx.mlx_ptr = mlx_init();
	utils = *pre_build(map, mlx);
	utils.move = 0;
	mlx_key_hook(utils.win_ptr, keys, &utils);
	mlx_hook(utils.win_ptr, 17, 0, cursur, NULL);
	mlx_loop(mlx.mlx_ptr);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\nArgument not valid\n");
		exit(1);
	}
	so_long(av[1]);
	return (0);
}

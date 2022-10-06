/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:35:10 by aabeid            #+#    #+#             */
/*   Updated: 2021/12/22 09:57:39 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_move(t_mlx *mlx, int n)
{
	char	*str;

	str = ft_itoa(n);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img1, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 15, 13, 0xFFD700, str);
	free(str);
}

void	move_right(t_mlx *mlx)
{
	if (mlx -> map[mlx->px][mlx->py + 1] != '1')
	{
		if (mlx -> map[mlx->px][mlx->py + 1] == 'C')
		{
			mlx->collect--;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img2,
				(mlx->y + 1) * 50, (mlx->x) * 50);
			mlx -> map[mlx->px][mlx->py + 1] = '0';
		}
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img5,
			(mlx->py += 1) * 50, (mlx->px) * 50);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img2,
			(mlx->y * 50), (mlx->x * 50));
		if (mlx -> map[mlx->px][mlx->py - 1] == 'E')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img3,
				(mlx->y) * 50, (mlx->x) * 50);
		mlx->move++;
		print_move(mlx, mlx->move);
	}
}

void	move_left(t_mlx *mlx)
{
	if (mlx -> map[mlx->px][mlx->py - 1] != '1')
	{
		if (mlx -> map[mlx->px][mlx->py - 1] == 'C')
		{
			mlx->collect--;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img2,
				(mlx->y - 1) * 50, (mlx->x) * 50);
			mlx -> map[mlx->px][mlx->py - 1] = '0';
		}
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img5,
			(mlx->py -= 1) * 50, (mlx->px) * 50);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img2,
			(mlx->y * 50), (mlx->x * 50));
		if (mlx -> map[mlx->px][mlx->py + 1] == 'E')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img3,
				((mlx->y) * 50), (mlx->x) * 50);
		mlx->move++;
		print_move(mlx, mlx->move);
	}
}

void	move_down(t_mlx *mlx)
{
	if (mlx -> map[mlx->px + 1][mlx->py] != '1')
	{
		if (mlx -> map[mlx->px + 1][mlx->py] == 'C')
		{
			mlx->collect--;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img2,
				(mlx->y) * 50, (mlx->x + 1) * 50);
			mlx -> map[mlx->px + 1][mlx->py] = '0';
		}
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img5,
			(mlx->py * 50), (mlx->px += 1) * 50);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img2,
			(mlx->y * 50), (mlx->x * 50));
		if (mlx -> map[mlx->px - 1][mlx->py] == 'E')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img3,
				(mlx->y * 50), (mlx->x) * 50);
		mlx->move++;
		print_move(mlx, mlx->move);
	}
}

void	move_up(t_mlx *mlx)
{
	if (mlx -> map[mlx->px - 1][mlx->py] != '1')
	{
		if (mlx -> map[mlx->px - 1][mlx->py] == 'C')
		{
			mlx->collect--;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img2,
				(mlx->y) * 50, (mlx->x - 1) * 50);
			mlx -> map[mlx->px - 1][mlx->py] = '0';
		}
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img5,
			(mlx->py * 50), (mlx->px -= 1) * 50);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img2,
			(mlx->y * 50), (mlx->x) * 50);
		if (mlx -> map[mlx->px + 1][mlx->py] == 'E')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img3,
				(mlx->y) * 50, (mlx->x) * 50);
		mlx->move++;
		print_move(mlx, mlx->move);
	}
}

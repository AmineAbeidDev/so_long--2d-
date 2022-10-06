/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:32:47 by aabeid            #+#    #+#             */
/*   Updated: 2022/10/06 12:17:10 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long_utils/map_checker_utils/map_utils.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct mlx_params {
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img1;
	void			*img2;
	void			*img3;
	void			*img4;
	void			*img5;
	int				x;
	int				y;
	int				px;
	int				py;
	char			**map;
	unsigned int	collect;
	unsigned int	move;
}	t_mlx;

void	move_right(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_up(t_mlx *mlx);
void	move_down(t_mlx *mlx);
char	**map_checker(const char *path);
char	*get_next_line(int fd);
t_mlx	*map_builder(char **map, t_mlx mlx, int height, int width);
int		ft_strnstr(const char *haystack, const char *needle, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
void	ft_free(char **leaks);
int		check_members(char *line);
void	check_new_line(char *line);

#endif
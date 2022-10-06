/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:14:51 by aabeid            #+#    #+#             */
/*   Updated: 2022/10/06 12:07:43 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_members(char **map)
{
	int		ret;
	char	*line;

	line = map_to_line(map);
	if (check_members(line) == 0)
		return (0);
	ret = 0;
	if (ft_strmchr(line, 'P') != ft_strrchr(line, 'P'))
		return (0);
	if (ft_strrchr(line, 'C'))
		if (ft_strrchr(line, 'E'))
			if (ft_strrchr(line, '0'))
				if (ft_strmchr(line, 'P'))
					return (1);
	return (0);
}

int	map_shape(char **lines)
{
	size_t	i;
	size_t	wall_len;

	i = 1;
	wall_len = ft_strlen(lines[0]);
	while (lines[i] != NULL)
	{
		if (ft_strlen(lines[i]) != wall_len)
			return (0);
		i++;
	}
	if (wall_len == i)
		return (0);
	return (1);
}

int	map_walls(char **walls)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (walls[0][i] != '\0')
		if (walls[0][i++] != '1')
			return (0);
	while (walls[j] != NULL)
	{
		if (walls[j][0] != '1'
				|| walls[j][ft_strlen(walls[j]) - 1] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (walls[j - 1][i] != '\0')
		if (walls[j - 1][i++] != '1')
			return (0);
	return (1);
}

char	**map_getter(const char *path)
{
	char	*line;
	char	*buf;
	int		fd;
	char	**ret;

	line = NULL;
	buf = "";
	fd = open(path, O_RDONLY);
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		if (buf[0] == '\n')
		{
			free(buf);
			printf("Error\nthere is an empty line in your map\n");
			exit(1);
		}
		line = ft_strjoin(line, buf);
		free(buf);
		buf = get_next_line(fd);
	}
	free(buf);
	ret = ft_split(line, '\n');
	free(line);
	return (ret);
}

char	**map_checker(const char *path)
{
	char	**map;

	map = map_getter(path);
	if (map == NULL)
	{
		printf("Error\nyou don't have a map\n");
		exit (1);
	}
	if (1 == map_shape(map))
		if (1 == map_walls(map))
			if (1 == map_members(map))
				return (map);
	printf("Error\nCheck your map's \"walls\", \"shape\" and \"objects\"\n");
	free(map);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:40:04 by aabeid            #+#    #+#             */
/*   Updated: 2022/10/06 12:07:00 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*map_to_line(char **map)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = 0;
	while (map[ret] != NULL)
		line = ft_strjoin(line, map[ret++]);
	return (line);
}

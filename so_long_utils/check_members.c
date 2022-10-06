/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_members.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:03:26 by aabeid            #+#    #+#             */
/*   Updated: 2022/10/06 12:07:53 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_members(char *line)
{
	int	ret;

	ret = 0;
	while (line[ret] != '\0')
	{
		if (line[ret] != 'C' && line[ret] != 'E' && line[ret] != '0'
			&& line[ret] != '1' && line[ret] != 'P')
		{
			free(line);
			return (0);
		}
		ret++;
	}
	return (1);
}

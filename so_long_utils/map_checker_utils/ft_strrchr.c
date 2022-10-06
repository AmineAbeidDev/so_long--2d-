/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:37:47 by aabeid            #+#    #+#             */
/*   Updated: 2021/12/18 19:58:05 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

int	ft_strrchr(const char *str, int c)
{
	int		i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if ((char)str[i] == (char)c)
			return (i);
		i--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:59:30 by aabeid            #+#    #+#             */
/*   Updated: 2021/12/18 15:07:24 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	n_len;
	size_t	i;

	n_len = ft_strlen((char *) haystack);
	i = n_len - n;
	while (i <= (n_len) && ft_strlen(needle) <= ft_strlen(haystack)
		&& n > 0)
	{
		if ((haystack[i] == needle[0])
			&& (0 == ft_strncmp(&haystack[i], needle, n_len)))
			return (1);
		i++;
	}
	return (0);
}

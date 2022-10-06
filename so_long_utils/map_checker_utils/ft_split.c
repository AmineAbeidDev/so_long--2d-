/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:10:36 by aabeid            #+#    #+#             */
/*   Updated: 2021/12/15 10:01:42 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

static int	words_counter(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_strndup(const char *src, char c, int j)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (src[j + len] && src[j + len] != c)
		len++;
	p = (char *) malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (0);
	while (src[j + i] != '\0' && src[j + i] != c)
	{
		p[i] = src[j + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static char	**spliter(char const *s, char c, char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[j] != '\0')
	{
		if (s[j] == c || j == 0)
		{
			while (s[j] == c)
				j++;
			str[i] = ft_strndup(s, c, j);
			i++;
		}
		j++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	s = ft_strtrim(s, &c);
	if (s == NULL)
		return (NULL);
	str = malloc((words_counter((char *)s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	str = spliter(s, c, str);
	free((void *)s);
	return (str);
}

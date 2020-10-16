/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:02:03 by mki               #+#    #+#             */
/*   Updated: 2020/10/16 01:38:43 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		col_size(char const *s1, char c)
{
	char	*str;
	int		length;
	int		i;

	if (!s1)
		return (0);
	length = 0;
	str = (char *)s1;
	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

static int		row_size(char const *s1, char c)
{
	int		check;
	int		length;
	int		end;

	if (!*s1)
		return (0);
	end = 0;
	while (s1[end])
		end++;
	end--;
	while (s1[end] == c)
		end--;
	length = 0;
	check = 0;
	while (*s1 == c)
		s1++;
	while (*s1 && end-- != 0)
	{
		if (*s1 == c && check++ == 0)
			length++;
		else
			check = 0;
		s1++;
	}
	return (length + 1);
}

char			**ft_split(char const *s, char c)
{
	int		length;
	char	**ret;
	int		row;

	if (!s)
		return (0);
	row = 0;
	length = row_size(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (length + 1))))
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		length = col_size(s, c);
		if (!(ret[row] = (char *)malloc(sizeof(char) * length + 1)))
			return (0);
		ft_strlcpy(ret[row++], s, length + 1);
		while (*s != c && *s != '\0')
			s++;
	}
	ret[row] = NULL;
	return (ret);
}

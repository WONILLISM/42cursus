/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:57:06 by mki               #+#    #+#             */
/*   Updated: 2020/10/14 22:54:55 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	if (s[i] != c)
		cnt++;
	while (s[++i])
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			cnt++;
	return (cnt);
}

size_t			ft_free(char **ret, size_t wi)
{
	while (wi--)
		free(ret[wi]);
	return (1);
}

size_t			ft_fill(char const *s, char c, char **ret, size_t wc)
{
	size_t	wi;
	size_t	start;
	size_t	end;

	start = 0;
	while (s[start] == c)
		start++;
	wi = 0;
	while (s[start])
	{
		end = start;
		while (s[end] != c && s[end])
			end++;
		if (start != end && wi != wc)
		{
			if (!(ret[wi] = (char *)malloc(sizeof(char) * (end - start + 1))))
				return (ft_free(ret, wi));
			ft_strlcpy(ret[wi], s + start, end - start + 1);
			wi++;
			start = end;
		}
		if (start < ft_strlen(s))
			start++;
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = ft_word_count(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (wc + 1))))
		return (NULL);
	ret[wc] = NULL;
	if (ft_fill(s, c, ret, wc))
		return (NULL);
	return (ret);
}

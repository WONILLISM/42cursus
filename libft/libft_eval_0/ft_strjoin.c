/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:19:48 by mki               #+#    #+#             */
/*   Updated: 2020/10/12 21:33:26 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(ret = (char *)malloc(len_s1 + len_s2 + 1)))
		return (NULL);
	ft_memset(ret, 0, len_s1 + len_s2 + 1);
	ft_memmove(ret, s1, len_s1);
	ret += len_s1;
	ft_memmove(ret, s2, len_s2);
	ret -= len_s1;
	return (ret);
}

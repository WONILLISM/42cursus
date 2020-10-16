/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:22:25 by mki               #+#    #+#             */
/*   Updated: 2020/10/08 01:13:00 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;
	size_t	len;

	if (!src || !dst)
		return (0);
	ret = ft_strlen(src);
	if (dstsize)
	{
		len = (ret >= dstsize) ? dstsize - 1 : ret;
		ft_memmove(dst, src, len);
		dst[len] = '\0';
	}
	return (ret);
}

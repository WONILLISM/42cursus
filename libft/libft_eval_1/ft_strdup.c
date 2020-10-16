/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 22:45:17 by mki               #+#    #+#             */
/*   Updated: 2020/10/09 22:54:31 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*tmp;

	if (!(ret = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	tmp = ret;
	while (*s1)
		*tmp++ = *s1++;
	*tmp = '\0';
	return (ret);
}

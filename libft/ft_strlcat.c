/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:04:17 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/30 14:42:20 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_destlen(char *dst, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (dst[i] == '\0')
			return (i);
		i++;
	}
	return (size);
}

size_t			ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	j;
	size_t	len;
	size_t	i;

	len = ft_destlen(dst, size);
	if (len == size)
		return (size + ft_strlen(src));
	j = 0;
	i = len;
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len + ft_strlen(src));
}

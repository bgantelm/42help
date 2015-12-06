/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:44:16 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/28 23:12:51 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	char			*pdst;
	char			*psrc;
	unsigned char	pc;
	size_t			i;

	i = 0;
	pc = (unsigned char)c;
	pdst = (char *)dst;
	psrc = (char *)src;
	if (n != 0)
	{
		while (i < n)
		{
			pdst[i] = psrc[i];
			if (psrc[i] == c)
				return (&dst[i + 1]);
			i++;
		}
	}
	return (NULL);
}

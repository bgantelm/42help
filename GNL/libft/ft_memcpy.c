/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:44:16 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:57 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	char	*p1;
	char	*p2;
	size_t	i;

	i = 0;
	p1 = (char *)dst;
	p2 = (char *)src;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dst);
}

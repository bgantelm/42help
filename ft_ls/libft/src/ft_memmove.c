/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:44:16 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/30 14:52:42 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	char	*psrc;
	char	*pdst;
	char	*ptemp;
	size_t	i;

	i = 0;
	pdst = (char *)dst;
	psrc = (char *)src;
	ptemp = (char *)ft_memcpy((void *)ft_strdup((const char *)dst), src, len);
	while (i < len)
	{
		pdst[i] = ptemp[i];
		i++;
	}
	return (dst);
}

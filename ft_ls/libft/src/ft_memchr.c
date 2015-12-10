/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:02:13 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/27 23:44:52 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char	pc;
	unsigned char	*ps;
	size_t			i;

	i = 0;
	pc = (unsigned char)c;
	ps = (unsigned char *)s;
	while (i < n)
	{
		if (ps[i] == pc)
			return (&ps[i]);
		i++;
	}
	return (NULL);
}

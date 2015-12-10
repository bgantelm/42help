/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:50:21 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/28 23:13:09 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	car;
	unsigned char	*bis;

	i = 0;
	bis = (unsigned char *)b;
	car = (unsigned char)c;
	while (i < len)
	{
		bis[i] = car;
		i++;
	}
	return (b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:24:45 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/30 10:02:41 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void *zone;

	zone = malloc(sizeof(zone) * size);
	if (zone == NULL)
		return (NULL);
	ft_memset(zone, 0, size);
	return (zone);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:46:55 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/30 12:26:45 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t				i;
	unsigned char const	*p1;
	unsigned char const	*p2;

	p1 = (unsigned char const *)s1;
	p2 = (unsigned char const *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (p1[i] != '\0' && p2[i] != '\0' && p1[i] == p2[i] && i < n - 1)
		i++;
	return (p1[i] - p2[i]);
}

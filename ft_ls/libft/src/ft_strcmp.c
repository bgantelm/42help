/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:32:48 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/30 11:39:52 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strcmp(char const *s1, char const *s2)
{
	int					i;
	unsigned char const	*p1;
	unsigned char const	*p2;

	p1 = (unsigned char const *)s1;
	p2 = (unsigned char const *)s2;
	i = 0;
	while (p1[i] != '\0' && p2[i] != '\0' && p1[i] == p2[i])
		i++;
	return (p1[i] - p2[i]);
}

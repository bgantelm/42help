/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:39:24 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/27 20:29:59 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	if (s2[0] == '\0')
		return (char*)(s1);
	while (s1[i] != '\0' && n != 0 && i < n)
	{
		j = 0;
		c = i;
		while (s1[c] == s2[j] && c < n)
		{
			c++;
			j++;
			if (s2[j] == '\0')
				return (char*)(&s1[i]);
		}
		i++;
	}
	return (NULL);
}

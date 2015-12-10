/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:39:24 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/07 11:40:53 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(char const *s1, char const *s2)
{
	int i;
	int j;
	int c;

	i = 0;
	if (s2 == NULL)
		return (char*)(s1);
	while (s1[i] != '\0')
	{
		j = 0;
		c = i;
		while (s1[c] == s2[j])
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

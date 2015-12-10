/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:48:47 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/27 15:42:21 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(char const *s, int c)
{
	int i;
	int save;

	i = 0;
	save = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			save = i;
		i++;
	}
	if (s[i] == c)
		save = i;
	if (save != -1)
		return (char*)(&s[save]);
	return (NULL);
}

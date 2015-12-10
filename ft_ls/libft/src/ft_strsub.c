/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:05:32 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/07 10:35:13 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*strnew;
	size_t		i;

	i = 0;
	strnew = (char *)malloc(sizeof(strnew) * len + 1);
	if (strnew == NULL || s == NULL)
		return (NULL);
	while (i < len)
	{
		strnew[i] = s[start];
		i++;
		start++;
	}
	strnew[i] = '\0';
	return (strnew);
}

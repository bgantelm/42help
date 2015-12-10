/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:06:35 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/30 11:23:41 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*strnew;

	if (s == NULL || f == NULL)
		return (NULL);
	strnew = (char *)malloc(sizeof(*strnew) * ft_strlen(s));
	i = 0;
	while (s[i] != '\0')
	{
		strnew[i] = f(i, s[i]);
		i++;
	}
	return (strnew);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:06:35 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/30 11:23:11 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*strnew;

	if (s == NULL || f == NULL)
		return (NULL);
	strnew = (char *)malloc(sizeof(*strnew) * ft_strlen(s) + 1);
	if (strnew == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		strnew[i] = f(s[i]);
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:11:49 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/30 12:25:42 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strnew;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strnew = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (strnew == NULL)
		return (NULL);
	strnew = ft_strcpy(strnew, ft_strcat(ft_strdup(s1), s2));
	return (strnew);
}

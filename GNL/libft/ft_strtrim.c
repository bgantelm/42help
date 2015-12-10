/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:51:34 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/30 11:54:33 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		end;
	int		start;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	if (ft_strsub(s, start, end - start + 1) == NULL)
		return (NULL);
	return (ft_strsub(s, start, end - start + 1));
}

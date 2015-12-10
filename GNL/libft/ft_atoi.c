/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:17:44 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/28 23:13:19 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	int i;
	int n;
	int signe;

	i = 0;
	n = 0;
	signe = 1;
	while (nbr[i] == ' ' || nbr[i] == '\n' || nbr[i] == '\r'
	|| nbr[i] == '\t' || nbr[i] == '\f' || nbr[i] == '\v')
		i++;
	if (nbr[i] == '-')
		signe = -1;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (ft_isdigit(nbr[i]) == 1)
	{
		n = n * 10;
		n = n + nbr[i] - 48;
		i++;
	}
	return (n * signe);
}

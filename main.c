/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:49:07 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/12 10:44:31 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	main(void)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		ft_putendl(line);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:13:10 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/08 09:45:13 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_realloc(void *ptr, int count)
{
	void	*dup;

	dup = ft_memalloc((count + 1) * BUFF_SIZE + 1);
	if (ptr)
	{
		if (dup)
			ft_memcpy(dup, ptr, count * BUFF_SIZE);
		ft_memdel(&ptr);
	}
	return (dup);
}

static int	ft_separated(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		i++;
	}
	if (line[i] == '\0')
		return (0);
	if (line[i] == '\n')
	{
		line[i] = '\0';
		if (line[i + 1] == '\0')
			return (0);
	}
	return (1);
}

static int	check_line(char **tmp, int *i, char **buf, char ***line)
{
	ft_memdel((void **)tmp);
	if (*i == 2)
	{
		ft_memdel((void **)buf);
		return (0);
	}
	if (*i == 0)
	{
		**line = ft_strdup(*buf);
		*i = 1;
	}
	else
		**line += ft_strlen(**line) + 1;
	if (ft_separated(**line) == 0)
		*i = 2;
	ft_memdel((void **)buf);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	int			count;
	int			ret;
	char		*tmp;
	char		*buf;
	static int	i = 0;

	count = 0;
	tmp = (char *)malloc(sizeof(*tmp) * BUFF_SIZE);
	buf = (char *)malloc(sizeof(*buf) * BUFF_SIZE + 1);
	if (buf == NULL || tmp == NULL)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) != 0)
	{
		i = 0;
		ft_memcpy((buf + BUFF_SIZE * count), tmp, ret);
		if (ret == BUFF_SIZE)
		{
			count++;
			buf = ft_realloc(buf, count);
			if (buf == NULL || tmp == NULL)
				return (-1);
		}
		buf[BUFF_SIZE * count + ret] = '\0';
	}
	return (check_line(&tmp, &i, &buf, &line));
}

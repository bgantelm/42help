/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:21:26 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/10 12:23:54 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*init_list(DIR *opening)
{	
	t_file *list;
	struct dirent *info;

	list = NULL;
	while ((info = readdir(opening)))
		add_file(&list, new_file(info));
	return (list);
}

void	add_file(t_file **alist, t_file *new)
{
	t_file *cur;

	cur = *alist;
	if (cur == NULL)
		*alist = new;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
		new->next = NULL;
	}
}

t_file *new_file(struct dirent *info)
{
	t_file *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->info = info;
	new->next = NULL;
	return (new);
}

void	sort_files(t_file *list)
{
	struct dirent *temp;
	t_file *cur;
	cur = list;

	while (cur->next != NULL)
	{
		if (ft_strcmp(cur->info->d_name, cur->next->info->d_name) > 0)
		{
			temp = cur->info;
			cur->info = cur->next->info;
			cur->next->info = temp;
			cur = list;
		}
		cur = cur->next;
	}
}

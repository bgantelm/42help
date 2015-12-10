/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:50:50 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/10 18:41:11 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int print_files(DIR	*opening)
{
	t_file *list;

	if (opening == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	list = init_list(opening);
	sort_files(list);
	while (list != NULL)
	{
		if (ft_strncmp(list->info->d_name, ".", 1) != 0)
		{
			ft_putstr(list->info->d_name);
			ft_putchar(' ');
		}
		list = list->next;
	}
	ft_putchar('\n');
	return (0);
}

char    *ft_strcatpath(char *s1, const char *s2)
{
    char    *str1;
    char    *str2;

    str1 = s1;
    str2 = (char*)s2;
    while (*str1)
    {
        str1++;
    }
    while (*str2)
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '/';
	*str1 = '\0';
    return (s1);
}

int	print_R(DIR *opening)
{
	struct dirent	*info;
	DIR *open2;

	while ((info = readdir(opening)))
	{
		open2 = opendir(info->d_name);
		if (ft_strncmp(info->d_name, ".", 1) != 0)
		{
			if (open2)
			{
				ft_putstr(info->d_name);
				ft_putstr(" contient-> ");
				print_files(open2);
				print_R(open2);
			}
			else
			{
				ft_putstr(info->d_name);
				ft_putchar('\n');
			}
		}
	}
	closedir(opening);
	return (0);
}

int	main(int ac, char **av)
{
	DIR	*opening;
	opening = opendir(".//");
	if (opening == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (ac == 2)
	{
		if (strcmp(av[1], "-R") == 0)
		print_R(opening);
	}
	else if (ac == 1)
		print_files(opening);
	else
		ft_putstr("error\n");
}

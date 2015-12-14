/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:50:50 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/11 17:22:20 by bgantelm         ###   ########.fr       */
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
	*str1 = '/';
	str1++;
    while (*str2)
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
	*str1 = '\0';
    return (s1);
}

int	print_R(char *rep)
{
	DIR	*opening;
	struct dirent	*info;
	struct stat	st;

	opening = NULL;
	if ((opening = opendir(rep)) != NULL)
	{
		print_files(opening);
		chdir(rep);
		ft_putstr("\n./");
		ft_putstr(rep);
		ft_putstr("\n");
		while ((info = readdir(opening)))
		{
			if (ft_strncmp(info->d_name, ".", 1) != 0)
			{
				stat(info->d_name, &st);
				if (S_ISDIR(st.st_mode))
				{
					print_R(info->d_name);
				}
				else
				{
//					ft_putstr(info->d_name);
					ft_putstr("		");
				}
			}
		}
		chdir("..");
		ft_putchar('\n');
	}
	closedir(opening);
	return (0);
}

int	main(int ac, char **av)
{
	DIR	*opening;
	char	*rep;

	rep = NULL;
	opening = opendir(".//");
	if (opening == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (ac == 2)
	{
		print_R(".");
	}
	else if (ac == 1)
	{
		print_files(opening);
		av[1] = rep;
	}
	else
		ft_putstr("error\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:50:33 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/10 12:47:17 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_file
{
	struct dirent *info;
	struct s_file *next;
}				t_file;

t_file			*init_list(DIR *opening);
void			add_file(t_file **alist, t_file *new);
t_file			*new_file(struct dirent *info);
void			sort_files(t_file *list);

#endif

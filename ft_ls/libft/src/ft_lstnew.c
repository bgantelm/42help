/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:25:06 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/29 23:24:11 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	if (content == NULL)
	{
		element->content = NULL;
		element->content_size = 0;
	}
	else
	{
		element->content = (void *)ft_strdup((char *)content);
		element->content_size = content_size;
	}
	element->next = NULL;
	return (element);
}

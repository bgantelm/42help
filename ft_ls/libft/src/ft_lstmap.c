/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:41:52 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/30 09:39:59 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lstnew;
	t_list *cur;
	t_list *temp;

	temp = NULL;
	lstnew = NULL;
	cur = lst;
	while (cur != NULL)
	{
		temp = ft_lstnew(f(cur)->content, f(cur)->content_size);
		if (temp == NULL)
			return (NULL);
		ft_lstaddend(&lstnew, temp);
		cur = cur->next;
	}
	if (temp != NULL)
		temp->next = NULL;
	return (lstnew);
}

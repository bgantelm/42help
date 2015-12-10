/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:11:39 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/29 22:02:47 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *cur;

	while (*alst != NULL)
	{
		cur = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(cur);
	}
}

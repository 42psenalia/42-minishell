/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:53:43 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:01:42 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*oldlist;
	t_list	*node;
	void	*content;

	if (!f || !del || !lst)
		return (NULL);
	oldlist = lst;
	newlist = NULL;
	while (oldlist)
	{
		content = f(oldlist->content);
		node = ft_lstnew(content);
		if (!node)
		{
			ft_lstclear(&newlist, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&newlist, node);
		oldlist = oldlist->next;
	}
	return (newlist);
}

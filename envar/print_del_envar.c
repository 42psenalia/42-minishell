/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_del_envar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:17:42 by tbayrakt          #+#    #+#             */
/*   Updated: 2025/03/31 12:17:42 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envar.h"
#include <stdio.h>

void	print_envar_list(t_envar_list *list)
{
	t_envar	*var;

	while (list)
	{
		var = list->content;
		if (var->value)
			printf("%s=\"%s\"\n", var->key, var->value);
		list = list->next;
	}
}

void	delete_envar(char *key, t_envar_list **list)
{
	t_envar_list	*node;
	t_envar_list	*prev;
	t_envar			*envar;

	node = *list;
	prev = NULL;
	while (node)
	{
		envar = node->content;
		if (envar && ft_strcmp(envar->key, key) == 0)
		{
			if (prev)
				prev->next = node->next;
			else
				*list = node->next;
			ft_lstdelone(node, free_envar);
			return ;
		}
		prev = node;
		node = node->next;
	}
}

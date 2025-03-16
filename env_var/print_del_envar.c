/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_del_envar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:22 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:22 by psenalia         ###   ########.fr       */
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
			printf("%s=%s\n", var->key, var->value);
		list = list->next;
	}
}

void	delete_envar(char *key, t_envar_list **list)
{
	t_list	*node;

	node = find_node(key, *list);
	if (node == NULL)
		return ;
	ft_lstdelone(node, free_envar);
}

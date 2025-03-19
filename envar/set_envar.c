/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:25 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:25 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envar.h"

static t_list	*appendnew(char *head, char *body, t_envar_list **list)
{
	t_envar	*var;
	t_list	*node;

	var = create_envar(head, body);
	if (var == NULL)
		return (NULL);
	node = ft_lstnew(var);
	if (node == NULL)
	{
		free_envar(var);
		return (NULL);
	}
	ft_lstadd_back(list, node);
	return (node);
}

t_envar_list	*setenvar(char *head, char *body, t_envar_list **list)
{
	t_list	*node;
	t_list	*new;
	t_envar	*var;
	char	*temp;

	node = find_node(head, *list);
	if (node)
	{
		var = node->content;
		if (body)
		{
			temp = ft_strdup(body);
			if (temp == NULL)
				return (NULL);
			free(var->value);
			var->value = temp;
		}
		return (node);
	}
	new = appendnew(head, body, list);
	if (new == NULL)
		return (NULL);
	return (new);
}

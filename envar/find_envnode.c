/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_envnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:05 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:05 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envar.h"

t_envar_list	*find_node(char *head, t_envar_list *list)
{
	t_envar	*envar;

	while (list)
	{
		envar = list->content;
		if (ft_strcmp(envar->key, head) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_envnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:20:54 by tbayrakt          #+#    #+#             */
/*   Updated: 2025/03/31 12:20:54 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envar.h"

t_envar_list	*find_node(char *head, t_envar_list *list)
{
	t_envar	*envar;

	while (list)
	{
		if (!list->content)
		{
			ft_putstr_fd("Error: env var is NULL\n", STDERR_FILENO);
			return (NULL);
		}
		envar = list->content;
		if (envar->key && ft_strcmp(envar->key, head) == 0 && envar->value)
			return (list);
		list = list->next;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:16 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:16 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envar.h"

char	*get_envalue(char *key, t_envar_list *list)
{
	t_envar_list	*node;
	t_envar			*var;

	node = find_node(key, list);
	if (node == NULL)
		return (NULL);
	var = node->content;
	return (var->value);
}

char	**get_envarray(t_envar_list *list)
{
	char			**array;
	t_envar			*envar;
	size_t			i;

	array = malloc((ft_lstsize(list) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (list)
	{
		envar = list->content;
		if (envar->value)
			array[i] = va_strjoin(3, envar->key, "=", envar->value);
		else
			array[i] = va_strjoin(3, envar->key, "=", "");
		if (array[i] == NULL)
		{
			free_strarray(array, i);
			return (NULL);
		}
		i++;
		list = list->next;
	}
	array[i] = NULL;
	return (array);
}

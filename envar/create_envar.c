/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_envar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:00 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:00 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envar.h"

static bool	assignval(t_envar *var, char *val)
{
	if (val == NULL)
	{
		var->value = NULL;
		return (true);
	}
	var->value = ft_strdup(val);
	if (var->value == NULL)
		return (false);
	return (true);
}

t_envar	*create_envar(char *head, char *body)
{
	t_envar	*var;

	var = malloc(sizeof(t_envar));
	if (var == NULL)
		return (NULL);
	var->key = ft_strdup(head);
	if (var->key == NULL)
	{
		free(var);
		return (NULL);
	}
	if (!assignval(var, body))
	{
		free(var->key);
		free(var);
		return (NULL);
	}
	return (var);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_envar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:12 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:12 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envar.h"

void	free_envar(void *var)
{
	t_envar	*env;

	env = var;
	free(env->key);
	free(env->value);
	free(env);
}

void	free_envarlst(t_envar_list **list)
{
	ft_lstclear(list, free_envar);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkey_envar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:59:56 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 12:59:56 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envar.h"

bool	envar_keychk(char *key)
{
	if (!(ft_isalpha(*key) || *key == '_'))
		return (false);
	key++;
	while (*key)
	{
		if (!(ft_isalnum(*key) || *key == '_'))
			return (false);
		key++;
	}
	return (true);
}

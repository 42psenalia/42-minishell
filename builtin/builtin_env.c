/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:58:45 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 12:58:45 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

t_exit_status	builtin_env(int argc, char **argv, t_shell_data *data)
{
	(void) argc;
	(void) argv;
	print_envar_list(data->env_var_list);
	return (SUCCESS);
}

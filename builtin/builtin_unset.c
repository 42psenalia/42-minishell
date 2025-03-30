/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:59:18 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 12:59:18 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

t_exit_status	builtin_unset(int argc, char **argv, t_shell_data *data)
{
    int		i;

    if (!data || !data->envar_list)
    {
        fprintf(stderr, "Error: Environment list is NULL\n");
        return (ERROR);
    }
    i = 1;
    while (i < argc)
    {
        delete_envar(argv[i], &data->envar_list);
        i++;
    }
    return (SUCCESS);
}

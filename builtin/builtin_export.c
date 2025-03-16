/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:50:09 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:50:09 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "builtin.h"
#include "../libft/libft.h"
#include "../env_var/envar.h"

static void	sort_envp_arr(char **arr)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (arr[i + 1])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	print_declared_variables(t_env_var_list *list)
{
	char	**arr;
	int		i;
	char	**key_value;

	arr = get_envarray(list);
	if (arr == NULL)
		return (ERROR);
	sort_envp_arr(arr);
	i = 0;
	while (arr[i])
	{
		key_value = formkeyvar(arr[i]);
		if (ft_strlen(key_value[1]) == 0)
			arr[i][ft_strlen(arr[i]) - 1] = '\0';
		printf("declare -x %s\n", arr[i]);
		free_strarray(key_value, 2);
		i++;
	}
	free_strarray(arr, 0);
	return (SUCCESS);
}

static int	export_single_var(char *key_value_str, t_shell_data *data)
{
	char	**key_value_pair;
	char	*key_str;
	t_list	*node;

	if (ft_strchr(key_value_str, '='))
	{
		key_value_pair = split_env_var_line(key_value_str);
		if (key_value_pair == NULL)
			return (ENOMEM);
		if (!envar_keychk(key_value_pair[0]))
			return (ERROR);
		node = setenvar(key_value_pair[0], key_value_pair[1],
				&data->env_var_list);
		free_strarray(key_value_pair, 2);
		if (node == NULL)
			return (ENOMEM);
	}
	else
	{
		key_str = key_value_str;
		if (!envar_keychk(key_str))
			return (ERROR);
		setenvar(key_str, NULL, &data->env_var_list);
	}
	return (SUCCESS);
}

t_exit_status	builtin_export(int argc, char **argv, t_shell_data *data)
{
	t_exit_status	ret;
	int				export_status;
	int				i;

	if (argc == 1)
		return (print_declared_variables(data->env_var_list));
	ret = SUCCESS;
	i = 1;
	while (i < argc)
	{
		export_status = export_single_var(argv[i], data);
		if (export_status == ENOMEM)
			return (ENOMEM);
		else if (export_status == ERROR)
		{
			ret = ERROR;
			ft_putstr_fd("minishell: export: '", STDERR_FILENO);
			ft_putstr_fd(argv[i], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		}
		i++;
	}
	return (ret);
}

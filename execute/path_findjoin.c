/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_findjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:42 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:42 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*join_path(char **full_path, char *cmd)
{
	char	*full_path_with_cmd;

	printf("joining path\n");
	while (*full_path)
	{
		full_path_with_cmd = va_strjoin(3, *full_path, "/", cmd);
		if (access(full_path_with_cmd, X_OK) == SUCCESS)
			return (full_path_with_cmd);
		printf("not PATH: %s\n", full_path_with_cmd);
		free(full_path_with_cmd);
		full_path++;
	}
	return (NULL);
}

char	*find_path(char *key, t_list *env_var_lst, char *cmd)
{
	t_list		*path_node;
	t_envar		*env_var;
	char		*path;
	char		**full_path;

	if (!key || !env_var_lst)
		return (NULL);
	printf("not NULL input\n");
	path_node = find_node(key, env_var_lst);
	if (!path_node)
		return (NULL);
	printf("PATH found in env\n");
	env_var = (t_envar *)path_node->content;
	full_path = ft_split(env_var->value, ':');
	path = join_path(full_path, cmd);
	printf("found PATH: %s\n", path);
	free_strarray(full_path, 0);
	if (path != NULL)
	// {
	// 	free_strarray(full_path, 0);
		return (path);
	// }
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_envar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:09 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:09 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envar.h"

static void	form_shlvl(char *head, char **body)
{
	int		num;
	char	*temp;

	if (ft_strsmp(head, "SHLVL") == 0)
	{
		num = ft_atoi(*body);
		free(*body);
		temp = ft_itoa(num + 1);
		if (temp == NULL)
		{
			*body = NULL;
			return ;
		}
		*body = temp;
	}
}

char	**formkeyvar(char *envline)
{
	char	**keyvar;
	size_t	headlen;
	size_t	bodylen;

	keyvar = malloc(2 * sizeof(char *));
	if (keyvar == NULL)
		return (NULL);
	headlen = (ft_strlen(ft_strchr(envline, '=')) - ft_strlen(envline));
	bodylen = (ft_strlen(ft_strchr(envline, '=')) + 1);
	keyvar[0] = ft_substr(envline, 0, headlen);
	keyvar[1] = ft_substr(envline, headlen + 1, bodylen);
	if (keyvar[0] == NULL || keyvar[1] == NULL)
	{
		free(keyvar[0]);
		free(keyvar[1]);
		free(keyvar);
		return (NULL);
	}
	return (keyvar);
}

static bool	getenvline(char *envline, t_list **list)
{
	char	**key_var;
	t_list	*node;

	key_var = formkeyvar(envline);
	if (key_var == NULL)
		return (false);
	form_shlvl(key_var[0], &key_var[1]);
	if (key_var[1] == NULL)
		return (false);
	node = setenvar(key_var[0], &key_var[1], list);
	free_strarray(key_var, 2);
	if (node == NULL)
		return (false);
	return (true);
}

t_list	*form_envar(char **env)
{
	t_list	*list;

	list = NULL;
	while (*env)
	{
		if (!getenvline(*env, &list))
		{
			free_envarlst(&list);
			return (NULL);
		}
		env++;
	}
	return (list);
}

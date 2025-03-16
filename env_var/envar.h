/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:27:07 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/11 15:27:07 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVAR_H
# define ENVAR_H

# include "../libft/libft.h"

typedef t_list	t_envar_list;

typedef struct s_envar
{
	char	*key;
	char	*value;
}	t_envar;

// BASE
t_envar_list	*form_envar(char **env);
char			**formkeyvar(char *envline);
t_envar_list	*setenvar(char *head, char *body, t_envar_list **list);
t_envar			*create_envar(char *head, char *body);
t_envar_list	*find_node(char *head, t_envar_list *list);
void			free_envar(void *var);
void			free_envarlst(t_envar_list **list);

// BUILTIN
char			*get_envalue(char *key, t_envar_list *list);
char			**get_envarray(t_envar_list *list);
bool			envar_keychk(char *key);
void			print_envar_list(t_envar_list *list);
void			delete_envar(char *key, t_envar_list **list);

#endif

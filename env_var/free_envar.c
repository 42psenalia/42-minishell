#include "envar.h"

void	free_envar(void *var)
{
	t_envar *env;

	env = var;
	free(env->key);
	free(env->value);
	free(env);
}

void	free_envarlst(t_envar_list **list)
{
	ft_lstclear(list, free_envar);
}
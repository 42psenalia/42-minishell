#include "envar.h"
#include <stdio.h>

void	print_envar_list(t_envar_list *list)
{
	t_envar	*var;

	while (list)
	{
		var = list->content;
		if (var->value)
			printf("%s=%s\n", var->key, var->value);
		list = list->next;
	}
}

void	delete_envar(char *key, t_envar_list **list)
{
	t_list	*node;

	node = find_node(key, *list);
	if (node == NULL)
		return ;
	ft_lstdelone(node, free_envar);
}

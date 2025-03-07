#include "envar.h"

t_envar_list	*find_node(char *head, t_envar_list *list)
{
	t_envar	*envar;

	while (list)
	{
		envar = list->content;
		if (ft_strncmp(envar->key, head) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}
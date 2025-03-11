#include "../minishell.h"

void	add_token(t_tokens **head, t_token_type type, char *value)
{
	t_tokens	*new;
	t_tokens	*temp;

	new = malloc(sizeof(t_tokens));
	if (!new)
		return ;
	new->token_type = type;
	new->value = value;
	new->next = NULL;

	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

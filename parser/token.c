#include "parser.h"

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

t_token_type	get_token_type(char *str)
{
	if (!str)
		return (-1);
	printf("get_token %s\n", str);
	if (!ft_strcmp(str, "|"))
		return (PIPE);
	if (!ft_strcmp(str, "<"))
		return (REDIRIN);
	if (!ft_strcmp(str, ">"))
		return (REDIROUT);
	if (!ft_strcmp(str, "<<"))
		return (HEREDOC);
	if (!ft_strcmp(str, ">>"))
		return (APPEND);
<<<<<<< Updated upstream
	if (!ft_strcmp(str, "$"))
=======
	if (str[0] == '$')
		return (DOLLAR);
	if (str[0] == '\'')
		return (SQUOTE);
	if (str[0] == '"')
		return (DQUOTE);
	if (ft_strchr(str, '$'))
>>>>>>> Stashed changes
		return (DOLLAR);
	return (WORD);
}

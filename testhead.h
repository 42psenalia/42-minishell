/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testhead.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:07:25 by psenalia          #+#    #+#             */
/*   Updated: 2024/12/19 17:52:38 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_token_type
{
	SQUOTE,
	DQUOTE,
	DOLLAR,
	PIPE,
	REDIRIN,
	REDIROUT,
	HEREDOC,
	APPEND
}	t_token_type;

typedef struct s_tokens
{
	t_token_type	token_type;
}					t_tokens;

typedef struct s_tokencount
{
	int				squote;
	int				dquote;
	int				dollar;
	int				pipe;
	int				redirin;
	int				redirout;
	int				heredoc;
	int				append;
}	t_tokencount;


typedef struct s_pipseq
{
	// char			*in_file;
	// char			*out_file;
	// char			*command;
	int				fd_in;
	int				fd_out;
	pid_t			pipid;
	// struct s_pipseq	*prev;
	struct s_pipseq	*next;
}					t_pipseq;

// $?
// env

// ||
// &&
// *

#endif
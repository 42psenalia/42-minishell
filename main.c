/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbay1 <tanselbay1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:19 by tanselbay1        #+#    #+#             */
/*   Updated: 2024/12/12 16:36:16 by tanselbay1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

char *read_line(char *line)
{
    char *new_line;
    
    new_line = readline(line);
    if (!new_line)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", new_line);
    return (new_line);
}

void lsh_loop(char *av)
{
  char *line;
  //char **args;
  //int status;

    printf("> ");
    // TODO: Read a line of input
    line = read_line(av);
    // TODO: Parse the line into arguments
    //args = lsh_split_line(line);
    // TODO: Execute the command
    //status = lsh_execute(args);

    // TODO: Free the line and arguments
    free(line);
    //free(args);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
       lsh_loop(av[1]);
    }
    printf("\n");
    return (0);
}
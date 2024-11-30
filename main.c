/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbay1 <tanselbay1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:19 by tanselbay1        #+#    #+#             */
/*   Updated: 2024/11/30 17:58:41 by tanselbay1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void lsh_loop(void)
{
  char *line;
  char **args;
  int status;

    printf("> ");
    // TODO: Read a line of input
    line = lsh_read_line();
    // TODO: Parse the line into arguments
    args = lsh_split_line(line);
    // TODO: Execute the command
    status = lsh_execute(args);

    // TODO: Free the line and arguments
    free(line);
    free(args);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
       lsh_loop();
    }
    printf('\n');
    return (0);
}
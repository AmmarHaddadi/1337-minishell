/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:32:36 by ssallami          #+#    #+#             */
/*   Updated: 2025/04/30 18:34:26 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void sigint_handler(int signum)
{
    (void)signum;
    printf("\nexit\n");
    exit(0);
}

int main(void)
{
    signal(SIGINT, sigint_handler); // Ctrl+C
    char *input;

    while (1)
    {
        input = readline("minishell$ ");
        if (!input)
        {
            printf("exit\n");
            break;
        }
        // lexer → parser → execution
        
        // lexer
        t_token *tks = tokens(input);
        (void)tks;

        // t_cmd *cmds = parser(tks);
        
        // execute_commands(cmds);

        free(input);
    }

    return 0;
}

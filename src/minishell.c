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
        // t_token *tokens = lexer(input);
        // t_cmd *cmds = parser(tokens);
        // execute_commands(cmds);

        free(input);
    }

    return 0;
}
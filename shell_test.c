#include "holberton.h"

/* VERSION 0.1 Only parses on ' '*/
int input_parse(char *buffer, char **parsed_input)
{
        char *p_holder = NULL, delim[] = {' ', '\0'}, new[] = {'\n', '\0'};
        int j = 0;

	p_holder = strtok(buffer, delim);

        while (p_holder)
        {
                parsed_input[j] = p_holder;
                p_holder = strtok(NULL, delim);
                j++;
        }
	//check for newline on [j-1]
	parsed_input[j - 1] = strtok(parsed_input[j - 1], new);
	parsed_input[j] = p_holder;
        return (0);
}

int input_get(char *buffer, char **parsed_input)
{
        size_t size = CHAR_BUF_MAX;

        if (getline(&buffer, &size, stdin) == -1)
                return (1);
        input_parse(buffer, parsed_input);
        return (0);
}

void shell_exec(char **input)
{
        pid_t c_id;
        int status;

        c_id = fork();
        if (c_id == -1)
        {
                perror("Error:");
                exit(1);
        }
        else if (c_id == 0)
        {
		if (execve(input[0], input, NULL) == -1)
		{
			perror("Error:");
			exit(1);
		}
	}
	else
		wait(&status);
}

void shell_help(char **input)
{
        (void) input;
        printf("helped\n");
}

void shell_exit(char **input)
{
        int status = 0, i;


        if (input[1])
        {
                for (i = 0 ; input[1][i] != '\0'; i++)
                {
                        if (input[1][i] <= '9' && input[1][i] >= '0')
                                status = (status * 10) + (input[1][i] - '0');
                        else
                        {
                                perror("Error");
                                return;
                        }
                }
                exit(status);
        }
        else
        {
                exit(0);
        }
}

void (*input_exec(char **input))(char **)
{
        exec array[] = {
                {"exit", shell_exit},
                {"help", shell_help},
                {NULL, shell_exec}
        };
        int i = 0;

	while (array[i].cmd && strcmp(array[i].cmd, input[0]))
	{
		i++;
	}
	return(array[i].fun);
}

int main(void)
{
	char *buffer, *prompt = SHELL_PROMPT;
	char **parsed_input = NULL; /*malloc to max size*/
	int exit;

	if (!(buffer = malloc(sizeof(char) * CHAR_BUF_MAX)))
		return (-1);
	if(!(parsed_input = malloc(sizeof(void *) * 20)))
		return (-1);

	do
	{
		write(0, prompt, 7);
		exit = input_get(buffer, parsed_input);
		if (exit == 1)
			break;
		input_exec(parsed_input)(parsed_input);
		if (exit == 2)
			break;
	} while (1);
	printf("\n");
	free(buffer);
	free(parsed_input);
	return (0);
}

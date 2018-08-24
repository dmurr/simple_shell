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
			perror("**Error:");
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

extern char **environ;
char *get_path()
{
        const char *s = "PATH";
        int i, j = 0;

        for (i = 0; environ[i][j] != 0; i++)
        {
                for (j = 0; j < 4; j++)
                {
                        if (s[j] == environ[i][j])
			{
				if (j == 3)
					return (&environ[i][j+2]);

				continue;
			}
			else
                                break;
                }
        }
        return (0);
}

void process_rel_path(char **parsed_input)
{
	char *full_path, *path, *abs_path;
	char delim[] = {':', '\0'};
	char **ptr; // shell_exec expects a **ptr... ptr -> abs_path -> /bin/ls
	int i, j;

	ptr = &abs_path;

	if(!(abs_path = malloc(sizeof(char) * 1024)))
		return;

	full_path = get_path();

	path = strtok(full_path, delim);
	while(path)
	{
		for(i = 0; path[i] != '\0'; i++)
			abs_path[i] = path[i];
		abs_path[i] = '/';
		i++;

		for (j = 0; parsed_input[0][j] != '\0'; j++)
		{
			abs_path[i] = parsed_input[0][j];
			i++;
		}
		abs_path[i] = '\0';

		printf("abs_path = %s\n", abs_path);
		if (access(abs_path, F_OK) == 0)
			shell_exec(ptr);

		path = strtok(NULL, delim);
        }
	free(abs_path);
}

void direct_path(char **parsed_input)
{
        if (parsed_input[0][0] == '/')
                shell_exec(parsed_input);
        else
                process_rel_path(parsed_input);
}

void (*input_exec(char **input))(char **)
{
        exec array[] = {
                {"exit", shell_exit},
                {"help", shell_help},
                {NULL, direct_path}
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

#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SHELL_PROMPT "#cash$ "
#define CHAR_BUF_MAX 1024

int shell_main(void);

char **input_get(char *buffer, char **parsed_input);

char **input_parse(char *buffer, char **parsed_input);

#endif /*HOLBERTON_H*/

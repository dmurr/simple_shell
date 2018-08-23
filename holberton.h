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

/**
 * struct select - struct for selecting which operation to perform
 * on input string array
 *
 * @cmd: control string
 * @fun: correlating function pointer
 */

typedef struct select
   {
	   char *cmd;
	   void (*fun)();
 } exec;

int shell_main(void);

char **input_get(char *buffer, char **parsed_input);

char **input_parse(char *buffer, char **parsed_input);

void (*input_exec(char **parsed_input))(char **);

void shell_exec(char **parsed_input);

int _atoi(char *s);

#endif /*HOLBERTON_H*/

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
 * struct shell - struct for holding relevant variables related to the
 * functioning of the simple shell program
 *
 * @i_buf: input buffer for shell input
 * @p_buf: parsed string array for parsed input
 * @_env: parsed string array for environment variables
 * @name: argv[0] value for each shell call
 * @count: counter of number of loops shell main has initiated
 * @exit: used to trigger exit conditions
 */

typedef struct shell
{
	char *i_buf;
	char **p_buf;
	char **env;
	char *name;
	int count;
	int exit;
} shell;

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

int _strlen(char *s);

int _strcmp(char *s1, char *s2);

char *_strcat(char *dest, char *src);

char *int_arg(int input);

void *_calloc(unsigned int nmemb, unsigned int size);

void *memeset(void *a, int c, int size);

int input_get(struct shell cash);

int input_parse(struct shell cash);

void (*input_exec(struct shell cash))(struct shell);

void shell_exec(struct shell cash);

void shell_exit(struct shell cash);

void shell_env(struct shell cash);

void shell_error(struct shell cash, int error);

#endif /*HOLBERTON_H*/

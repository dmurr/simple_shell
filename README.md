# Simple Shell
### Description
This project is a recreation of the shell command line interpreter.
### Overview
This version of the shell has a collection of custom built-in commands along
with the functionality of running scripts from various paths.

## Repo Contents

|   ***File***    |  **Decription**                       |
|---------------|---------------------------------------|
|  `holberton.h` |  Header file that contains prototypes	|
|  `shell_main.c`	|  Main file |
|  `shell_helper.c` |  Helper functions |
|  `error_handler.c` |  Functions to print error messages	|
|  `shell_input_get.c`  | Read input from stdin |
|  `shell_input_parse.c`  |  Parses input  |
|  `direct_path.c`  | Determines if path is relative or absolute   |
|  `shell_input_exec.c`	     |  Executes absolute path of command  |
|  `rel_path.c`  | Converts relative path to absolute path	  |
|  `_strtok.c`  | Custom strtok function  |
|  `_getenv.c`  | Gets PATH from environment variables  |


### How to Use
Clone repo
```
git clone https://github.com/dmurr/simple_shell.git
```
Change directory to simple_shell
```
cd simple_shell/
```
Compile all the `.c` files
```
gcc -Wall -Werror -Wextra -pedantic *.c
```

### Builtins and commands
Listed below are the builtin commands used. For additional information refer to the man page in the terminal.
```
man ./man_1_simple_shell
```
#### Builtins:
* `env` prints environment variables
* `exit` exit program


### Authors
*Diego Murray* - [Github](https://github.com/dmurr) || [Twitter](https://twitter.com/diegocmurray)

*Cameron Eng* - [Github](https://github.com/c_eng/) || [Twitter](https://twitter.com/c33Eng)

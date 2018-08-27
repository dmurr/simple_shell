#include "holberton.h"

void process_rel_path(struct shell cash)
{
        char *full_path, *path, *abs_path;
        const char delim[] = {':', '\0'};
        int i, j;

        if(!(abs_path = malloc(sizeof(char) * 1024)))
                return;

        full_path = _getenv(cash);

        path = _strtok(full_path, delim);
        while(path)
        {
                for(i = 0; path[i] != '\0'; i++)
                        abs_path[i] = path[i];
                abs_path[i] = '/';
                i++;

                for (j = 0; (cash.p_buf)[0][j] != '\0'; j++)
                {
                        abs_path[i] = (cash.p_buf)[0][j];
                        i++;
                }
                abs_path[i] = '\0';

                if (access(abs_path, F_OK) == 0)
                {
                        (cash.p_buf)[0] = abs_path;
                        shell_exec(cash);
                        break;
                }
                path = _strtok(NULL, delim);

	}
}

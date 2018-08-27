#include "holberton.h"

void direct_path(struct shell cash)
{
        if ((cash.p_buf)[0][0] == '/')
                shell_exec(cash);
        else
                process_rel_path(cash);
}

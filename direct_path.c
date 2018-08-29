#include "holberton.h"

/**
 * direct_path - Determines whether input is an absolute or
 * relative path and directs to the proper function.
 * @cash: main struct
 *
 */
void direct_path(struct shell cash)
{
	if ((cash.p_buf)[0][0] == '/')
		shell_exec(cash);
	else
		process_rel_path(cash);
}

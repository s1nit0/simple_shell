#include "shell.h"

/**
 * lst_builtins - search for match and cmd_exec the associate builtin
 * @data: struct for the program's data
 * Return: Returns the return of the function cmd_execd is there is a match,
 * otherwise returns -1.
 **/
int lst_builtins(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};


	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{

		if (str_compare(options[iterator].builtin, data->command_name, 0))
		{

			return (options[iterator].function(data));
		}

	}
	return (-1);
}

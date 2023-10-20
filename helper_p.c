#include "shell.h"

/**
 * _print - writes a array of chars in the standar output
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}
/**
 * print_arr - writes a array of chars in the standar error
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_arr(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}

/**
 * _print_error - writes a array of chars in the standart error
 * @data: a pointer to the program's data'
 * @errorcode: error code to print
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print_error(int errorcode, data_of_program *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		print_arr(data->program_name);
		print_arr(": ");
		print_arr(n_as_string);
		print_arr(": ");
		print_arr(data->tokens[0]);
		if (errorcode == 2)
			print_arr(": Illegal number: ");
		else
			print_arr(": can't cd to ");
		print_arr(data->tokens[1]);
		print_arr("\n");
	}
	else if (errorcode == 127)
	{
		print_arr(data->program_name);
		print_arr(": ");
		print_arr(n_as_string);
		print_arr(": ");
		print_arr(data->command_name);
		print_arr(": not found\n");
	}
	else if (errorcode == 126)
	{
		print_arr(data->program_name);
		print_arr(": ");
		print_arr(n_as_string);
		print_arr(": ");
		print_arr(data->command_name);
		print_arr(": Permission denied\n");
	}
	return (0);
}

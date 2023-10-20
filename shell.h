#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#include "macros.h"

/**
 * struct info - struct with the info of the program
 * @program_name: name of the program
 * @input_line: line of input
 * @command_name: name of the command
 * @exec_counter: number of executions
 * @file_descriptor: file descriptor to be readed
 * @tokens: array of tokens
 * @env: environment variables
 * @alias_list: list of alias
 * Description: struct with the info of the program
*/
typedef struct info
{
    char *program_name;
    char *input_line;
    char *command_name;
    int exec_counter;
    int file_descriptor;
    char **tokens;
    char **env;
    char **alias_list;
} data_of_program;

/**
 * struct builtins - struct with the builtins
 * @builtin: name of the builtin
 * @function: function of the builtin
 * Description: struct with the builtins
*/
typedef struct builtins
{
    char *builtin;
    int (*function)(data_of_program *data);
} builtins;

void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);
void prpt_msg(char *prompt, data_of_program *data);
void ctrl_c(int opr UNUSED);
int my_get_line(data_of_program *data);
int check_and_or(char *array_commands[], int i, char array_operators[]);
void var_exp(data_of_program *data);
void alias_exp(data_of_program *data);
int make_buff(char *buffer, char *str_to_add);
void tokenize(data_of_program *data);
char *_strtok(char *line, char *delim);
int cmd_exec(data_of_program *data);
int lst_builtins(data_of_program *data);
char **tokenize_path(data_of_program *data);
int find_program(data_of_program *data);
void free_array_of_pointers(char **directories);
void free_recurrent_data(data_of_program *data);
void free_all_data(data_of_program *data);
int builtin_exit(data_of_program *data);
int builtin_cd(data_of_program *data);
int SWD(data_of_program *data, char *new_dir);
int builtin_help(data_of_program *data);
int builtin_alias(data_of_program *data);
int builtin_env(data_of_program *data);
int builtin_set_env(data_of_program *data);
int builtin_unset_env(data_of_program *data);
char *env_get_key(char *name, data_of_program *data);
int env_set_key(char *key, char *value, data_of_program *data);
int env_remove_key(char *key, data_of_program *data);
void print_environ(data_of_program *data);
int _print(char *string);
int print_arr(char *string);
int _print_error(int errorcode, data_of_program *data);
int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *string1, char *string2, int number);
char *str_concat(char *string1, char *string2);
void str_reverse(char *string);
void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);
int print_alias(data_of_program *data, char *alias);
char *get_alias(data_of_program *data, char *alias);
int set_alias(char *alias_string, data_of_program *data);

#endif /* SHELL_H */

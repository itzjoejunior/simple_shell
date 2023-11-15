#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>




/* PROTOTYPES IN ORDER OF USAGE */


char *env(char *buffer);
char *env(char *variable_name);
int print_error(char *shell_name, char **tokens, int error_code);

int custom_strlen(char *str);
int custom_strncmp(const char *str1, char *str2, int num);
char *custom_strcpy(char *dest, char *src);
char *custom_strcat(char *dest, char *src);
char *custom_strdup(char *str);


int custom_getline(char **input_buffer, size_t *buffer_size);
char *custom_memcpy(char *dest, char *src, unsigned int num);


char *custom_strtok(char *input_str, const char *delimiters);
char *custom_strchr(const char *search_str, int target_char);


int print_str(int file_desc, const char *str);
int print_int(int file_desc, int num);

int check_exit_command(const char *command);
int handle_exit(char *buffer);
void tokenize(char *buffer, char **my_token);


void handle_exit_code(int status_code);
void create_and_execute(char *program_name, char **my_token);
void execute_external_command(char *program_name, char **my_token);
void execute_command(char *program_name, char **my_token);

extern char **environ;
char *get_path(char *command);
char *find_executable_path(char *command, char *my_path);
char *find_env_variable(char *variable_name);
int strncmp(const char *str1, const char *str2, size_t n);
#endif


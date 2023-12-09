#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

void execmd(char *command, char **argv);
char *get_location(char *command);
int printEnve();
void print_string(char *esra);




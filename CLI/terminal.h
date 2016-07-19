#ifndef TERMINAL_H_ 
#define TERMINAL_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include <iostream>
#include "autocomplete.h"

using namespace std;

#define CMD_LEN 100
#define HELP_MAX 100

#define back 0
#define fwd !back

//////////////////////////////////////////////////////////////////////////////////

extern char command[CMD_LEN];

typedef struct
{
	char *command;
	void(*foo)(char *);
	char help[5][HELP_MAX];
}menu_t;



void add_to_command(char c);
int delete_from_command();
void show_help();
void execute();
void listen();


#endif // TERMINAL_H_
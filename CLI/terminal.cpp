// terminal.cpp : Defines the entry point for the console application.
//
#include "terminal.h"

char command[CMD_LEN];
int count = 0;

void CMD1(char* cmd) 
{
	printf("CMD1\n");
}

void CMD2(char* cmd)
{
	printf("CMD2\n");
}

void CMD3(char* cmd)
{
	printf("CMD3\n");
}

void CMD4(char* cmd)
{
	printf("CMD4\n");
}

menu_t menu[] =
{
	{ "cmd1",&CMD1,{ "CMD1 help" } },
	{ "cmd2",&CMD2,{ "CMD2 help" } },
	{ "cmd3",&CMD3,{ "CMD3 help" } },
	{ "cmd4",&CMD4,{ "CMD4 help" } },
};

void add_to_command(char c)
{
	if (count < CMD_LEN)
		command[count++] = c;
}

int delete_from_command()
{
	printf("\b \b");
	if (count > 0)
	{
		command[--count] = '\0';
		count = (count < 0) ? count++ : count;
	}
}

void show_help()
{
	int i;
	printf("\n\t\tList of commands\n\n");
	for (i = 0; i < sizeof(menu) / sizeof(*menu); i++)
	{
		printf("\t %s\n", menu[i].command);
	}
}

void execute()
{
	int i = 0;
	char *str;
	if (count >1)
		printf("\n");
	for (i = 0; i<sizeof(menu) / sizeof(*menu); i++)
	{
		_strlwr(command);
		str = strstr(command, menu[i].command);
		if (str == command)
		{
			if (strchr(str, '?') != NULL) {
				printf("%s\n", menu[i].help);
				break;
			}
			menu[i].foo(str + strlen(menu[i].command));
			break;
		}
	}
	memset(command, '\0', 100);
	count = 0;
}

void listen()
{
	char c;
	trie* node = &root;
	while (1)
	{
		printf("\rterm# %s", command);
		c = _getch();
		switch (c)
		{
		case '\n': // Enter
		case '\r':
			execute();
			node = &root;
			break;

		case 9:
			autocomplete(node);
			break;

		case '?':
			show_help();
			break;

		case 3: // ^C
		case 27: // escape
			return;
			break;

		case '\b':
		case 127:
			delete_from_command();
			break;

		default:
			if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') || (c <= 'Z')) || ((c >= '0') && (c <= '9')))
			{
				add_to_command(c);
				node = autocomplete_helper(node, c);
			}
			break;
		}
	}

}
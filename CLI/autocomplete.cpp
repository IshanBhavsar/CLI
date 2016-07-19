/////////////////auto complete.c ///////////////////////

#include "autocomplete.h"
#define CMD_LEN 100
extern char command[CMD_LEN];

trie root;

trie* AddNode(trie* node, char alphabet)
{
	int i;
	if (alphabet != 0)
		alphabet -= 'a';
	else
		alphabet = 26;

	if (node->node[alphabet] == NULL)
	{
		trie* newnode = (trie*)malloc(sizeof(trie));
		for (i = 0; i<27; i++)
			newnode->node[i] = NULL;
		newnode->prev = node;
		node->node[alphabet] = newnode;
	}

	return node->node[alphabet];
}

bool AddtoDict(char * word)
{
	trie* node = &root;
	root.prev = NULL;
	while (*word)
	{
		node = AddNode(node, *word);
		word++;
	}
	node = AddNode(node,0);
	return true;
}

void printNode(trie* node, char* cmd)
{
	if (node)
	{
		char cmd1[100] = {'\0'};
		int i;
		int isempty = true;
		for (i = 0; i < 26; i++)
			if (node->node[i] != NULL)
				isempty = false;
		if (node->node[26] != NULL)
		{
			printf("%s%s\n",command, cmd);
		}
		for (i = 0; i < 26; i++)
			if (node->node[i] != NULL)
			{
				strcpy(cmd1,cmd);
				cmd1[strlen(cmd1)]= i + 'a';
				printNode(node->node[i],cmd1);
			}
	}
}

void autocomplete(trie* node)
{
	printf("\n");
	printNode(node,"");
}

trie* autocomplete_helper(trie* node, char alphabet,int dir)
{
	if (node)
	{
		//printf("\nchar %c %s\n",alphabet,dir?"added":"removed");
		if(dir)
		{
			if (node->node[alphabet - 'a'] != NULL)
			{
				return node->node[alphabet - 'a'];
			}
			else
				return NULL;
		}
		else
		{
			printf("back\n");
			return node->prev;
		}
			
	}
	else
	{
		return NULL;
	}
	
}
/////////////////auto complete.c ///////////////////////

#include "autocomplete.h"
#define CMD_LEN 100
extern char command[CMD_LEN];

char printbuff[100];
int printcnt = 0;
trie root;

trie* AddNode(trie* node, char alphabet)
{
	if (alphabet != 0)
		alphabet -= 'a';
	else
		alphabet = 26;

	if (node->node[alphabet] == NULL)
	{
		trie* newnode = (trie*)malloc(sizeof(trie));
		int i;
		for (i = 0; i<27; i++)
			newnode->node[i] = NULL;
		node->node[alphabet] = newnode;
	}

	return node->node[alphabet];
}

bool AddtoDict(char * word)
{
	trie* node = &root;
	while (*word)
	{
		node = AddNode(node, *word);
		word++;
	}
	node = AddNode(node,0);
	return true;
}

void printNode(trie* node)
{
	if (node)
	{
		int i;
		int isempty = true;
		for (i = 0; i < 26; i++)
			if (node->node[i] != NULL)
				isempty = false;
		if (node->node[26] != NULL)
		{
			printf("%s%s\n", command,printbuff);
			if (isempty)
			{
				memset(printbuff, 0, 100);
				printcnt = 0;
			}
		}
		for (i = 0; i < 26; i++)
			if (node->node[i] != NULL)
			{
				printbuff[printcnt++] = i + 'a';
				printNode(node->node[i]);
			}
	}
}

void autocomplete(trie* node)
{
	printf("\n");
	printNode(node);
}

trie* autocomplete_helper(trie* node, char alphabet)
{
	if (node)
	{
		if (node->node[alphabet - 'a'] != NULL)
			return node->node[alphabet - 'a'];
		else
			return NULL;
	}
	else
	{
		return NULL;
	}
}
#ifndef AUTOCOMPLETE_H_  
#define AUTOCOMPLETE_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "terminal.h"

#define true 1
#define false 0

extern char printbuff[100];
extern int printcnt;

//// 0-26 correspond to respective letters 27th location meanse NULL or the word ends here.
typedef struct nodetype
{
	struct nodetype* node[27];
	struct nodetype* prev;
}trie;

extern trie root;


trie* AddNode(trie* node, char alphabet);
bool AddtoDict(char * word);
void printNode(trie* node,char* cmd);
void autocomplete(trie* node);
trie* autocomplete_helper(trie* node, char alphabet, int dir);

#endif // AUTOCOMPLETE_H_



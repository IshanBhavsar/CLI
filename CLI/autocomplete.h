#ifndef AUTOCOMPLETE_H_   /* Include guard */
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
}trie;

extern trie root;


trie* AddNode(trie* node, char alphabet);
bool AddtoDict(char * word);
void printNode(trie* node);
void autocomplete(trie* node);
trie* autocomplete_helper(trie* node, char alphabet);

#endif // AUTOCOMPLETE_H_



/************************************************************************
University of Leeds
School of Computing
COMP2932- Compiler Design and Construction
The Compiler Module

I confirm that the following code has been developed and written by me and it is entirely the result of my own work.
I also confirm that I have not copied any parts of this program from another person or any other source or facilitated someone to copy this program from me.
I confirm that I will not publish the program online or share it with anyone without permission of the module leader.

Student Name:
Student ID:
Email:
Date Work Commenced:
*************************************************************************/
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "compiler.h"
#define COMPILER_C


int InitCompiler ()
{
	return 1;
}

IdentifierStrct* compareId(SymbolTable* st) {
	//for id in id stack check if it exists in current scope or parent scope
	if (st == NULL) {
		return NULL;
	}
	// for id in id stack
	for(int i = 0; i <= IdStack.topIndex; i++) {
		if (IndexTable(IdStack.data[i]->name, IdStack.data[i]->scope) == -1 && IndexParents(IdStack.data[i]->name, IdStack.data[i]->scope) == -1) {
			return IdStack.data[i]; // Return 0 if the symbol is found in the current table
		}

	}

	return NULL;
}

ParserInfo compile (char* dir_name)
{
	ParserInfo p;
	// write your code below
	// open the directory
	DIR *dir, *predir;
	dir = opendir(dir_name);
	predir = opendir(".");
	if (dir == NULL || predir == NULL) {
		perror("Unable to open directory");
		p.er = lexerErr;
		return p;
	}
	struct dirent *entry;
	struct dirent *preentry;
	//compille all files in the same directory as the directory given

	while ((entry = readdir(dir)) != NULL) {
		// check if it's a jack file
			char file_name[1000];
			sprintf(file_name, "%s/%s", dir_name, entry->d_name);
			if (strstr(file_name, ".jack") == NULL) {
				// printf("File: %s is not a jack file\n", file_name);
				continue;
			}
			// else {
			 	// printf("File: %s is a jack file\n", file_name);
			// }
			InitParser(file_name);
			// printf("Current error: %d\n", p.er);
			p = Parse();
			StopParser();
			if (p.er != none) {
				// printf("Error in file: %s\n", file_name);
				// printf("Error type: %d, line: %i,token: %s\n", p.er, p.tk.ln, p.tk.lx);
				break;
			}

			
	}
	// close the directory
	closedir(dir);
	// print all symbols in all scopes
	printf("Symbol Table:\n");
	for (int i = 0; i < ProgramScope.len; i++) {
		printf("Name: %s, Type: %d, Kind: %d\n", ProgramScope.table[i]->name, ProgramScope.table[i]->type, ProgramScope.table[i]->kind);
	}
	// print all identufiers in all scopes
	for (int i = 0; i <= IdStack.topIndex; i++) {
		printf("Identifier: %s, Scope: %s\n", IdStack.data[i]->name, IdStack.data[i]->scope->table[0]->name);
	}
	IdentifierStrct* err = compareId(&ProgramScope);
	if (err == NULL){
		printf("No undeclared identifiers\n");
	} else {
		printf("Undeclared identifier: %s, Scope: %s\n", err->name, err->scope->table[0]->name);
		p.er = undecIdentifier;
		p.tk = err->token;
	}
	return p;
}

int StopCompiler ()
{
	ProgramScope.childCount = 0;
	ProgramScope.parent = NULL;
	for (int i = 0; i < 127; i++) {
		free(ProgramScope.children[i]);
	}
	for (int i = 0; i < ProgramScope.len; i++) {
		free(ProgramScope.table[i]);
	}
	for (int i = 0; i < IdStack.topIndex; i++) {
		free(IdStack.data[i]);
	}
	IdStack.topIndex = -1;
	for (int i = 0; i < SymbolStack.topIndex; i++) {
		free(SymbolStack.data[i]);
	}
	SymbolStack.topIndex = -1;

	return 1;
}


#ifndef TEST_COMPILER
// int main ()
// {
// 	InitCompiler ();
// 	ParserInfo p = compile ("Pong");
// 	#ifdef PrintError
// 	PrintError (p);
// 	#endif
// 	StopCompiler ();
// 	return 1;
// }
#endif

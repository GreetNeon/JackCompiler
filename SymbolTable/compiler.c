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
#include "compiler.h"
#define COMPILER_C


int InitCompiler ()
{
	return 1;
}


ParserInfo compile (char* dir_name)
{
	ParserInfo p;
	// write your code below
	// open the directory
	DIR *dir;
	dir = opendir(dir_name);
	if (dir == NULL) {
		perror("Unable to open directory");
		p.er = lexerErr;
		return p;
	}
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		// check if it's a jack file
			char file_name[256];
			sprintf(file_name, "%s", entry->d_name);
			if (strstr(file_name, ".jack") == NULL) {
				printf("File: %s is not a jack file\n", file_name);
				continue;
			}
			else {
				printf("File: %s is a jack file\n", file_name);
			}
			InitParser(file_name);
			printf("Current error: %d\n", p.er);
			p = Parse();

			if (p.er != none) {
				printf("Error in file: %s\n", file_name);
				printf("Error type: %d, line: %i,token: %s\n", p.er, p.tk.ln, p.tk.lx);
				break;
			}

			StopParser();
	}

	p.er = none;
	return p;
}

int StopCompiler ()
{


	return 1;
}


#ifndef TEST_COMPILER
int main ()
{
	InitCompiler ();
	ParserInfo p = compile ("Pong");
	#ifdef PrintError
	PrintError (p);
	#endif
	StopCompiler ();
	return 1;
}
#endif

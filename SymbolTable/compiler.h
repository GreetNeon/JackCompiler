#ifndef COMPILER_H
#define COMPILER_H

//#define TEST_COMPILER    // uncomment to run the compiler autograder

#include "parser.h"
#include "symbols.h"

SymbolTable ProgramScope;
Stack SymbolStack; // Stack for symbol table scopes
Stack IdentifierStack; // Stack for identifiers

int InitCompiler ();
ParserInfo compile (char* dir_name);
int StopCompiler();

#endif

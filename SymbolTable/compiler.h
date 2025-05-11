#ifndef COMPILER_H
#define COMPILER_H

//#define TEST_COMPILER    // uncomment to run the compiler autograder

#include "parser.h"
#include "symbols.h"

SymbolTable ProgramScope;
Stack SymbolStack; // Stack for symbol table scopes
IdentifierStack IdStack; // Stack for identifiers
SpecialIdStack SpIdStack; // Stack for special identifiers
int count;

int InitCompiler ();
IdentifierStack cleanIdStack(IdentifierStack* s);

ParserInfo compile (char* dir_name);
int StopCompiler();

#endif

#ifndef SYMBOLS_H
#define SYMBOLS_H

#include "lexer.h"
#include "parser.h"

// define your own types and function prototypes for the symbol table(s) module below
typedef struct{
    char name[128];
    char type[128];
    char kind[128];
    int calls;
} Symbol;

typedef struct{
    Symbol table[1280];
    SymbolTable child_tables[128];
} SymbolTable;

void InsertSymbol(Symbol s);
void LocateSymbol(char* name);


#endif

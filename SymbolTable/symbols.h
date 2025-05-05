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
    struct Symbol* parent;
    struct Symbol* children;
    struct Symbol* next;
} Symbol;

typedef struct{
    Symbol table[1280];
    int len;
} SymbolTable;

Symbol CreateSymbol(char* Name, char* Type, char* Kind);
Symbol CreateChildSymbol(char* Name, char* Type, char* Kind, Symbol* parent);
void InsertSymbol(Symbol s);
void LocateSymbol(char* name);


#endif

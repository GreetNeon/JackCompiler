
/************************************************************************
University of Leeds
School of Computing
COMP2932- Compiler Design and Construction
The Symbol Tables Module

I confirm that the following code has been developed and written by me and it is entirely the result of my own work.
I also confirm that I have not copied any parts of this program from another person or any other source or facilitated someone to copy this program from me.
I confirm that I will not publish the program online or share it with anyone without permission of the module leader.

Student Name:Teon Green
Student ID:201734612
Email:sc23tg@leeds.ac.uk
Date Work Commenced:27/04/25
*************************************************************************/

// To Run
#include "symbols.h"
#include <string.h>
#include <stdio.h>


SymbolTable ProgramScope; ProgramScope.len = 0; // Initialize the length of the symbol table to 0

Symbol CreateSymbol(char* Name, char* Type, char* Kind){
    Symbol TempSymbol;
    strcpy(TempSymbol.name, Name);
    strcpy(TempSymbol.type, Type);
    strcpy(TempSymbol.kind, Kind);
    TempSymbol.calls = 0;
    #ifdef ProgramScope
    //DO this
    ProgramScope.table[ProgramScope.len] = TempSymbol;
    ProgramScope.len++;
    #else
    printf("Compiler Not Initialized");
    #endif
}
void InsertSymbol(Symbol s){

}

int main(){
    return 0;
}
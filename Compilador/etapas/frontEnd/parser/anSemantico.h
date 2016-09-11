/*
 * anSemantico.h
 *
 *  Created on: 10/09/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef ANSEMANTICO_H_
#define ANSEMANTICO_H_

#include "anSintatico.h"

typedef struct SymbolTable {

} SymbolTable;

SymbolTable typeChecking(ParseTree);
SymbolTable objectBinding(ParseTree);
SymbolTable definitiveAssigment(ParseTree);

#endif /* ANSEMANTICO_H_ */

/*
 * anSintatico.h
 *
 *  Created on: 10/09/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef ANSINTATICO_H_
#define ANSINTATICO_H_

#include "../anLexico.h"

typedef struct ParseTable {

} ParseTable;

typedef struct ParseTree {

} ParseTree;

// Analisadores Top-down
ParseTree topDownParsing(Token);

// Analisadores Bottom-up
ParseTable simplePrecedenceParser(Token);
ParseTable LRParser(Token);
ParseTable CYK(Token);
ParseTable shiftReduceParser(Token);
ParseTable recursiveAscedentParser(Token);

ParseTree bottomUpParsing(Token);

#endif /* ANSINTATICO_H_ */

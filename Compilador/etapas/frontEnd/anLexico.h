/*
 * anLexico.h
 *
 *  Created on: 10/09/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef ANLEXICO_H_
#define ANLEXICO_H_

#include <stdio.h>

typedef struct Lexeme {

} Lexeme;

typedef struct Token {

} Token;

Lexeme scanner(FILE *);
Token evaluator(Lexeme);
void lexer(FILE *);

#endif /* ANLEXICO_H_ */

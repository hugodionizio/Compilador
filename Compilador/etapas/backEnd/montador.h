/*
 * montador.h
 *
 *  Created on: 10/09/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef MONTADOR_H_
#define MONTADOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMBUFF 100

typedef enum boolean {
	false,
	true
} boolean;
typedef boolean bool;

typedef struct Teste {
	int num;
	char ch;
} Teste;

boolean converter(FILE *, FILE *, char *);
int _converter(FILE *, FILE *, char *);
int mainMontador (int, char *[]);

#endif /* MONTADOR_H_ */

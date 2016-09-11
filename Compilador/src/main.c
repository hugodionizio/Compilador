/*
 * main.c
 *
 *  Created on: 10/09/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */

/*
anLexico.c
anSintatico.c
anSematico.c
geraCodInterm.c
optimizCod.c
geraCodFinal.c
montador.c
tratErros.c
contadorSecoes.c
TabelaConversão
*/

#include "../etapas/middleEnd/CodOptim.h"
#include "../etapas/backEnd/montador.h"

int main(int argc, char **argv) {
	FILE* codFonte;
	Token token;
	ParseTree pTree;
	SymbolTable sTable;
	IntermCode intermCode;
	OptimCode optimCode;

	// Análise léxica
	lexer(codFonte);

	// Análise sintática
	topDownParsing(token);
	bottomUpParsing(token);

	// Análise semântica
	typeChecking(pTree);
	objectBinding(pTree);
	definitiveAssigment(pTree);

	// Geração do código intermediário
	generateIntermediateCode(sTable);

	// Otimização do código intermediário
	generateOptimeCode(intermCode);

	// Geração do código assembly
	generateFinalCode(optimCode);

	// Montagem do código assembly em linguagem de máquina
	mainMontador(argc, argv);

	return (0);
}


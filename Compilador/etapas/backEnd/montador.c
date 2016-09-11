/*
 * montador (mpg)
 * This file is part of CompiladorPortugolG
 *
 * Copyright (C) 2016 - Hugo Dionizio Santos
 *
 * CompiladorPortugolG is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * CompiladorPortugolG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CompiladorPortugolG. If not, see <http://www.gnu.org/licenses/>.
 */

#include "montador.h"

boolean converter(FILE *asmFile, FILE *binFile, char *asmName) {
	bool sucess = true, novaIteracao = true;
	char mneumonics[] = {}; // MIPS ou Intel
	char instructions[] = {}; // Hexadecimal
	char *tmp;
	char buffer[TAMBUFF], aux[TAMBUFF];
	Teste t = {1, 'a'};
	
	tmp = (char *)malloc(strlen(asmName)*sizeof(char));
	strcpy(tmp, strtok(asmName, "."));
	strcat(asmName, ".asm");
	strcat(tmp, ".bin");
	printf("Montando o arquivo \"%s\" no executável \"%s\"...\n", asmName, tmp);	

	asmFile = fopen(asmName, "r");
	if (asmFile == NULL) {
		sucess = false;
		perror("Erro na abertura do arquivo");
	}
	else {
		binFile = fopen(tmp, "wb");
	
		while(!feof(asmFile) && novaIteracao) {
			if (fgets(buffer, TAMBUFF, asmFile) == NULL)
				novaIteracao = false;
			if (novaIteracao) {
				fputs(strtok(buffer, "#\r\n"), stdout);
				if (buffer[0] != '#' && buffer[0] != '\r' && buffer[0] != '\n') {
					puts("\n");
					strcat(buffer, "\n");
					fputs(buffer, binFile);
				}
			}
		}
//		fwrite(&t, sizeof(Teste), 1, binFile);		
		fclose(asmFile);
		fclose(binFile);
	}
			
	return sucess;
}

int _converter(FILE *asmFile, FILE *binFile, char *asmName) {
	int sucess = 1;

	if (converter(asmFile, binFile, asmName))
		sucess = 1;
	else
		sucess = 0;
		
	return sucess;
}

int mainMontador (int argc, char *argv[]) {
	FILE *asmFile;
	FILE *binFile;
	
	if (argc > 1) {		
		if (converter(asmFile, binFile, argv[1]))
			printf("Código executável gerado.\n");
		else
			printf("Código corrompido ou mal formado.\n");			
	}
	else
		printf("Montador: erro fatal: sem arquivos de entrada\nMontagem abortada.\n");

	return (0);
}

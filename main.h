#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct infoArquivo {
	float sepalLength;
	float sepalWidth;
	float petalLength;
	float petalWidth;
	int tipo;
}; typedef struct infoArquivo infArq;

enum Algoritmo {
    ALG1,
    ALG2
};

int contains( char *string, char *substring );

void atribuindoInfosArquivo( infArq *cmds, FILE *f );

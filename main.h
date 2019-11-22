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

enum Tipo {
	IRIS_SETOSA, 
	IRIS_VERSICOLOUR,
	IRIS_VIRGINICA
};

int contains( char *string, char *substring );

void atribuindoInfosArquivo( infArq *cmds, FILE *f );

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmoKNN.h"

enum Algoritmo {
    ALG1,
    ALG2
};

int contains( char *string, char *substring );

void atribuindoInfosArquivo( infArq *cmds, FILE *f );

void printaArquivo( infArq *cmds );

void embaralhar(infArq *vet, int vetSize);

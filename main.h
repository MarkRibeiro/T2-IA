#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmoKNN.h"

enum Algoritmo {
    KNN,
    ADD
};

int contains( char *string, char *substring );

void atribuindoInfosArquivo( infArq *cmds, FILE *f );

void printaArquivo( infArq *cmds, int eleNum );

int embaralhar(infArq *vet, int vetSize);

void aviso();

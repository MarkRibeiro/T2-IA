#include "InfoArquivo.h"

double distanciaDados( infArq d1, infArq d2);
int *dadosMaisProximos( int dado, infArq *todos, int qtd );
int algoritmoKNN( infArq *todos, int qtd, int idx, int debug );
void preencheComInt( int *indexDosProximos, int tam, int valor );
void preencheComDouble( double *indexDosProximos, int tam, double valor );
int retornaIndexMaior( double *distanciaDosProximos, int qtd );

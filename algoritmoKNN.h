#include "InfoArquivo.h"

double distanciaDados( infArq d1, infArq d2);
int *dadosMaisProximos( int dado, infArq *todos, int qtd, int qtdElemTreinamento );
int algoritmoKNN( infArq *todos, int qtdElem, int qtdElemTreinamento, int idx, int debug );
void preencheComInt( int *indexDosProximos, int tam, int valor );
void preencheComDouble( double *indexDosProximos, int tam, double valor );
int retornaIndexMaior( double *distanciaDosProximos, int qtd );

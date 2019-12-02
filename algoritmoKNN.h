#include "InfoArquivo.h"

double distanciaDados( infArq d1, infArq d2);
int *dadosMaisProximos( int dado, infArq *todos, int qtd );
int algoritmoKNN( infArq *todos, int qtd, int idx );
void preencheCom( int *indexDosProximos, int tam, int valor );

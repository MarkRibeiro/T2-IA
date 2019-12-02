#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmoKNN.h"

/*  NUMERO DE TIPOS:
 *    0 Iris Setosa
 *    1 Iris Versicolour
 *    2 Iris Virginica
 *
 ************************/

const int NUM_TIPOS = 3;

int DEBUG;

/* estrutura.
 * 
 * Dado {
 * 
	float sepalLength;
	float sepalWidth;
	float petalLength;
	float petalWidth;
    int tipo;
 * }
 * 
 * 
 */

int algoritmoKNN( infArq *todos, int qtd, int idx, int debug ) {
    DEBUG = debug;
    int *dadosProximos = (int*)malloc(sizeof(int)*qtd);
    dadosProximos = dadosMaisProximos( idx, todos, qtd );
    int *contadorPorTipo = (int*)malloc(sizeof(int)*NUM_TIPOS);
    if( DEBUG ) {
        printf("index selecionado %d e seus dados:\n", idx);
        printf( "%f,%f,%f,%f,", (todos[idx].sepalLength), (todos[idx].sepalWidth), (todos[idx].petalLength), (todos[idx].petalWidth));
        if( todos[idx].tipo == IRIS_SETOSA ) {
            printf("IRIS_SETOSA\n");
        } else if( todos[idx].tipo == IRIS_VERSICOLOUR ) {
            printf("IRIS_VERSICOLOUR\n");
        } else if( todos[idx].tipo == IRIS_VIRGINICA ) {
            printf("IRIS_VIRGINICA\n");
        }
        printf("======================\n");
        printf("próximos %d index:\n", qtd);
        for( int i = 0; i < qtd; i++ ) {
            printf("index: %d\n", dadosProximos[i]);
        }
    }
    for( int i = 0; i < qtd; i++ ) {
        if( todos[dadosProximos[i]].tipo == IRIS_SETOSA ) {
            contadorPorTipo[IRIS_SETOSA]++;
        } else if( todos[dadosProximos[i]].tipo == IRIS_VERSICOLOUR ) {
            contadorPorTipo[IRIS_VERSICOLOUR]++;
        } else if( todos[dadosProximos[i]].tipo == IRIS_VIRGINICA ) {
            contadorPorTipo[IRIS_VIRGINICA]++;
        }
    }
    
    if( DEBUG ) {
        printf("contadores SETOSA = %d\n", contadorPorTipo[IRIS_SETOSA]);
        printf("contadores VERSICOLOUR = %d\n", contadorPorTipo[IRIS_VERSICOLOUR]);
        printf("contadores VIRGINICA = %d\n", contadorPorTipo[IRIS_VIRGINICA]);
    }
    int tipoDoDado = 0;
    int maior = 0;
    for( int i = 0; i < NUM_TIPOS; i++ ) {
        if( contadorPorTipo[i] > maior ) {
            tipoDoDado = i;
            maior = contadorPorTipo[i];
        }
    }
    return tipoDoDado;
}


double distanciaDados( infArq d1, infArq d2) {
    double ret = pow( d1.sepalLength- d2.sepalLength , 2 ) + pow( d1.sepalWidth - d2.sepalWidth, 2 ) +
    pow( d1.petalLength - d2.petalLength, 2 ) + pow( d1.petalWidth - d2.petalWidth, 2 ); 
    return sqrt(ret);
}

int retornaIndexMaior( double *distanciaDosProximos, int qtd ) {
    double maior = 0.0;
    int indexMaior = 0;
    for( int i = 0; i < qtd; i++ ) {
        if( distanciaDosProximos[i] > maior ) {
            maior = distanciaDosProximos[i];
            indexMaior = i;
        }
    }
    return indexMaior;
    
}

int *dadosMaisProximos( int dado, infArq *todos, int qtd ) {
    int *indexDosProximos = (int*)malloc(sizeof(int)*qtd);
    double *distanciaDosProximos = (double*)malloc(sizeof(double)*qtd);
    preencheComInt( indexDosProximos, qtd, 0 );
    preencheComDouble( distanciaDosProximos, qtd, 99.0 );
    for( int aux = 0; aux < 150; aux++ ) {
        if( dado == aux ) {
            continue;
        }
        double distancia = distanciaDados( todos[dado], todos[aux] );
//         printf("distancia: %lf\n", distancia);
        int indexMaior = retornaIndexMaior( distanciaDosProximos, qtd );
        if( distancia < distanciaDosProximos[indexMaior] ) {
            indexDosProximos[indexMaior] = aux;
            distanciaDosProximos[indexMaior] = distancia;
        }
    }
    if( DEBUG ) {
        for( int i = 0; i < qtd; i++ ) {
            printf("distancia[%d] = %lf\n", i, distanciaDosProximos[i]);
        }
    }
    return indexDosProximos;
}
void preencheComInt( int *indexDosProximos, int tam, int valor ) {
    for( int i = 0; i < tam ; i++ ) {
        indexDosProximos[i] = valor;
    }
}

void preencheComDouble( double *indexDosProximos, int tam, double valor ) {
    for( int i = 0; i < tam ; i++ ) {
        indexDosProximos[i] = valor;
    }
}


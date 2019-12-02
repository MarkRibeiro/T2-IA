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

int algoritmoKNN( infArq *todos, int qtd, int idx ) {
    int *dadosProximos = (int*)malloc(sizeof(int)*qtd);
    dadosProximos = dadosMaisProximos( idx, todos, qtd );
    int *contadorPorTipo = (int*)malloc(sizeof(int)*NUM_TIPOS);
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
    for( int i = 0; i < qtd; i++ ) {
        if( todos[dadosProximos[i]].tipo == IRIS_SETOSA ) {
            contadorPorTipo[IRIS_SETOSA]++;
        } else if( todos[dadosProximos[i]].tipo == IRIS_VERSICOLOUR ) {
            contadorPorTipo[IRIS_VERSICOLOUR]++;
        } else if( todos[dadosProximos[i]].tipo == IRIS_VIRGINICA ) {
            contadorPorTipo[IRIS_VIRGINICA]++;
        }
    }
    
    printf("contadores Setosa = %d\n", contadorPorTipo[IRIS_SETOSA]);
    printf("contadores VERSICOLOUR = %d\n", contadorPorTipo[IRIS_VERSICOLOUR]);
    printf("contadores VIRGINICA = %d\n", contadorPorTipo[IRIS_VIRGINICA]);
    
    int tipoDoDado = 0;
    for( int i = 0; i < NUM_TIPOS; i++ ) {
        int maior = 0;
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

int organizaVetorProximos( int *vetorProximos, int *distanciaDosProximos, int qtd ) {
    int j = 0;
    for( int i = 0; j < qtd; i++ ) {
        j = i + 1;
        if( distanciaDosProximos[i] < distanciaDosProximos[j] ) {
            // vetor index
            int aux = vetorProximos[j];
            vetorProximos[j] = vetorProximos[i];
            vetorProximos[i] = aux;
            // vetor distancias
            aux = distanciaDosProximos[j];
            distanciaDosProximos[j] = distanciaDosProximos[i];
            distanciaDosProximos[i] = aux;
        }
    }
}

int *dadosMaisProximos( int dado, infArq *todos, int qtd ) {
    int *indexDosProximos = (int*)malloc(sizeof(int)*qtd);
    int *distanciaDosProximos = (int*)malloc(sizeof(int)*qtd);
    preencheCom( indexDosProximos, qtd, 0 );
    preencheCom( distanciaDosProximos, qtd, 99 );
    for( int aux = 0; aux < 150; aux++ ) {
        if( dado == aux ) {
            continue;
        }
        double distancia = distanciaDados( todos[dado], todos[aux] );
        //printf("distancia: %lf\n", distancia);
        organizaVetorProximos( indexDosProximos, distanciaDosProximos, qtd );
        if( distancia < distanciaDosProximos[0] ) {
            indexDosProximos[0] = aux;
            distanciaDosProximos[0] = distancia;
        }
    }
    return indexDosProximos;
}

void preencheCom( int *indexDosProximos, int tam, int valor ) {
    for( int i = 0; i < tam ; i++ ) {
        indexDosProximos[i] = valor;
    }
}



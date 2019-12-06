#include"main.h"

int main( int argc, char *argv[ ] ) {
    int algoritmo;
    FILE *f;
    int qtdElem;
    int qtdElemTreinamento;
    int qtd, attNum;
    if( (f = fopen("iris.data", "r") ) == NULL) {
        printf("Erro na abertura do arquivo\n");
        return 0;
    }
    int entradaCerta = 1; // 0 - falso.  1 - correto

    if( contains(argv[1], "knn" ) ) {
        algoritmo = ALG1;
        if( argc != 4 ) {
            entradaCerta = 0;
        }
        qtdElem = atoi(argv[2]);
        qtdElemTreinamento = atoi(argv[3]);
    } else if( contains(argv[1], "alg2" ) ) {
        algoritmo = ALG2;
    } else {
        entradaCerta = 0;
    }
    
    if( !entradaCerta ) {
        printf("Execute o programa assim:\nPara AlgKNN:\n> ./main knn <num_elementos> <num_elementos_treinamento>\n> algoritmo pode ser alg1 ou alg2.\nEX: ./main alg1\n\n");
        return 0;
    }

    // Alocando estrutura com infos do arq inserido      
    infArq *cmds = (infArq*) malloc(150 * sizeof(infArq));

    atribuindoInfosArquivo( cmds, f);
    embaralhar( cmds, 150);
    
    int acerto = 0;
    if( algoritmo == ALG1 ) {
        for( int idx = qtdElemTreinamento; idx < 150; idx ++ ) {
            // int qtdElem = QUANTIDADE DE ELEMENTOS PRÓXIMOS --> estou marretando no código, mas podemos colocar como valor de entrada.
            // int indx = INDEX DO ELEMENTO A SER TESTADO E VERIFICADO. --> temos que entender o que precisaremos fazer. se vao ser varios ou soment 1 elemento
            //int indx = 78;
            int debug = 0;
            int result = algoritmoKNN( cmds, qtdElem, qtdElemTreinamento, idx, debug );
            if( debug ) {
                if( result == IRIS_SETOSA ) {
                    printf(" index %d é IRIS SETOSA \n", idx);
                } else if( result == IRIS_VERSICOLOUR ) {
                    printf(" index %d é IRIS_VERSICOLOUR \n", idx);
                } else if( result == IRIS_VIRGINICA ) {
                    printf(" index %d é IRIS_VIRGINICA \n", idx);
                }
            }
            if( result == cmds[idx].tipo ) {
                acerto++;
            }
        }
        printf( "Quantidade de Elementos: %d\nQuantidade de Elementos Treinamento: %d\n", qtdElem, qtdElemTreinamento );
    }
    if( algoritmo == ALG2 ) {
        for( int idx = 0; idx < 150; idx ++ ) {
        // int qtd = QUANTIDADE DE ELEMENTOS PRÓXIMOS --> estou marretando no código, mas podemos colocar como valor de entrada.
        // int indx = INDEX DO ELEMENTO A SER TESTADO E VERIFICADO. --> temos que entender o que precisaremos fazer. se vao ser varios ou soment 1 elemento
            //int indx = 78;
            int debug = 0;
            int result = algoritmoADD( cmds[idx], attNum );
            if( debug ) {
                if( result == IRIS_SETOSA ) {
                    printf(" index %d é IRIS SETOSA \n", idx);
                } else if( result == IRIS_VERSICOLOUR ) {
                    printf(" index %d é IRIS_VERSICOLOUR \n", idx);
                } else if( result == IRIS_VIRGINICA ) {
                    printf(" index %d é IRIS_VIRGINICA \n", idx);
                }
            }
            if( result == cmds[idx].tipo ) {
                acerto++;
            }
        }
    }
    printf( "Acertos: %d\n", acerto );
    // Printa valores lidos:
    //printaArquivo( cmds );

    free(cmds);
    fclose(f);

    return 0;
}

void printaArquivo( infArq *cmds ) {
    for( int aux = 0; aux < 150; aux++ ) {
        printf( "[%d]%.1f,%.1f,%.1f,%.1f,", aux, (cmds[aux].sepalLength), (cmds[aux].sepalWidth), (cmds[aux].petalLength), (cmds[aux].petalWidth));
        if( cmds[aux].tipo == IRIS_SETOSA ) {
            printf("IRIS_SETOSA\n");
        } else if( cmds[aux].tipo == IRIS_VERSICOLOUR ) {
            printf("IRIS_VERSICOLOUR\n");
        } else if( cmds[aux].tipo == IRIS_VIRGINICA ) {
            printf("IRIS_VIRGINICA\n");
        }
    }
}

int contains( char *string, char *substring ) {
    if(strstr(string, substring) != NULL) {
        return 1;
    } else {
        return 0;
    }
}

 
void atribuindoInfosArquivo( infArq *cmds, FILE *f ) {
    char tipo[20];
    int aux = 0;

    while( fscanf (f, "%lf,%lf,%lf,%lf,%s\n", &(cmds[aux].sepalLength), &(cmds[aux].sepalWidth), &(cmds[aux].petalLength), &(cmds[aux].petalWidth), tipo) != EOF ){
        if( contains(tipo, "setosa") ) {
            cmds[aux].tipo = IRIS_SETOSA;
        } else if( contains(tipo, "versicolor") ) {
            cmds[aux].tipo = IRIS_VERSICOLOUR;
        } else if( contains(tipo, "virginica") ) {
            cmds[aux].tipo = IRIS_VIRGINICA;
        }
        aux++;
        
    }
}

void embaralhar(infArq *vet, int vetSize)
{
	for (int i = 0; i < vetSize; i++)
	{
		int r = rand() % vetSize;

		infArq temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
}

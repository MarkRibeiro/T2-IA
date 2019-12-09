#include"main.h"
#include"time.h"


const int NUM_EMBARALHADAS = 100;

int main( int argc, char *argv[ ] ) {
    int algoritmo;
    FILE *f;
    int qtdElem;
    int qtdElemTreinamento;
    int attNum;
    int entradaCerta = 1; // 0 - falso.  1 - correto
    int eleNum;
    int prop;
    int tamCombinacao = argc-4;
    int *combinacao = (int*)malloc(sizeof(int)*(tamCombinacao));
    
    time_t initAlg = time(0);

    if(argc < 3){
        aviso();
        return 0;
    }
    
    if( contains(argv[1], "knn" ) ) {
        if( (f = fopen("iris.data", "r") ) == NULL) {
            printf("Erro na abertura do arquivo\n");
            return 0;
        }
        algoritmo = KNN;
        eleNum = 150;
        if( argc < 5 ) {
            entradaCerta = 0;
        }
        qtdElem = atoi(argv[2]);
        qtdElemTreinamento = atoi(argv[3]);
        
        int aux = 0;
        for( int i = 4; i < argc; i++ ) {
            combinacao[aux] = atoi(argv[i]);
            if( combinacao[aux] > 4  || combinacao[aux] < 1) {
                entradaCerta = 0;
            }
            aux++;
        }
    } else if( contains(argv[1], "add" ) ) {

        algoritmo = ADD;
        if(argc != 4){
            entradaCerta = 0;
        }
        attNum = atoi(argv[2]);
        if(attNum > 2){
            entradaCerta = 0;
        }
        if( (f = fopen(argv[3], "r") ) == NULL) {
            printf("Erro na abertura do arquivo\n");
            return 0;
        }
        if(contains(argv[3], "1_3")){
            eleNum = 50;
            prop = 0;
        } else if(contains(argv[3], "2_3")){
            eleNum = 100;
            prop = 1;
        } else {
            eleNum = 150;
            prop = 2;
        }

    } else {
        entradaCerta = 0;
    }
    
    if( !entradaCerta ) {
        aviso();
        return 0;
    }
    infArq *cmds = (infArq*) malloc(eleNum * sizeof(infArq));

    
    atribuindoInfosArquivo( cmds, f);
    time_t finalAprendizado = time(0);
    
    
    for( int i = 0; i < NUM_EMBARALHADAS; i++ ) {
        if ( embaralhar( cmds, eleNum) %2 ) {
            i++;
        }
    }
    time_t inicioElemento;
    time_t finalElemento;
    int acerto = 0;
    if( algoritmo == KNN ) {
        for( int idx = qtdElemTreinamento; idx < eleNum; idx ++ ) {
            inicioElemento = time(0);
            int debug = 0;
            int result = algoritmoKNN( cmds, qtdElem, qtdElemTreinamento, idx, debug, combinacao, tamCombinacao );
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
            finalElemento = time(0);
        }
        printf( "Quantidade de Elementos: %d\nQuantidade de Elementos Treinamento: %d\n", qtdElem, qtdElemTreinamento );
    }
    if( algoritmo == ADD ) {
        for( int idx = 0; idx < eleNum; idx ++ ) {
            inicioElemento = time(0);
            int debug = 0;
            int result = algoritmoADD( cmds[idx], attNum, prop );
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
            finalElemento = time(0);
        }
    }
    
    printf( "Acertos: %d\nTempo de Aprendizado: %ld\nTempo de Classificação de um Elemento: %ld\n", acerto, (finalAprendizado - initAlg), (finalElemento - inicioElemento) );
    free(cmds);
    fclose(f);

    return 0;
}

void printaArquivo( infArq *cmds, int eleNum ) {
    for( int aux = 0; aux < eleNum; aux++ ) {
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

int embaralhar(infArq *vet, int vetSize)
{
    int r;
	for (int i = 0; i < vetSize; i++)
	{
        srand(time(0));
		r = rand() % vetSize;

		infArq temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
	
	return r;
}

void aviso(){
    printf("Execute o programa assim:\nPara KNN:\n> ./main knn <num_elementos> <num_elementos_treinamento> <combinacao_de_atributos>\n=> Combinacao de atributos define quais atributos você quer usar: 1-Sepal Length 2-Sepal Width 3- Petal Length 4- Petal Width.\nVocê pode utilizar a combinacao que quiser.\n\nEX1: ./main knn 10 100 3 4\n==> Para rodar o KNN, buscando 10 elementos, com 100 elementos no conjunto de treino e utilizando os atributos Petal para tal.\nEX2: ./main knn 10 100 1 2 3\n==> Para rodar o KNN, buscando 10 elementos, com 100 elementos no conjunto de treino e utilizando os atributos Sepal e Petal Length para tal.\n\nPara ADD:\n> ./main add <num_de_atributos> <arquivo_com_dados>\n=> Num de atributos define quantos atributos você quer usar: 1-Petal Width 2-Petal Width e Petal Length.\n=> Arquivo com dados define quantos elementos serao usados: iris.data (150 elementos), iris2_3.data (100 elementos), iris1_3.data (50 elementos)\n\nEX1: ./main add 2 iris1_3.data\n==> Para rodar o ADD, com 50 elementos e atributos Petal para tal.\nEX2: ./main add 1 iris.data\n==> Para rodar o ADD, com 150 elementos e atributo Petal Width para tal.\n");
}

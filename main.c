#include"main.h"

int main( int argc, char *argv[ ] ) {
    int algoritmo;
    FILE *f;

    if( (f = fopen("iris.data", "r") ) == NULL) {
            printf("Erro na abertura do arquivo\n");
            return 0;
        }

    if( argc == 2 ) {
        if( contains(argv[1], "alg1" ) ) {
            algoritmo = ALG1;
        } else if( contains(argv[1], "alg2" ) ) {
            algoritmo = ALG2;
        } else {
            printf("Insira um algoritmo válido! alg1 ou alg2\n");
            return 0;
        }
    } else if( argc != 2 ) {
        printf("Execute o programa assim:\n> ./main <algoritmo>\n> algoritmo pode ser alg1 ou alg2.\nEX: ./main alg1\n\n");
        return 0;
    } 

    // Alocando estrutura com infos do arq inserido      
    infArq *cmds = (infArq*) malloc(150 * sizeof(infArq));

    atribuindoInfosArquivo( cmds, f);
    
    
    if( algoritmo == ALG1 ) {
    // int qtd = QUANTIDADE DE ELEMENTOS PRÓXIMOS --> estou marretando no código, mas podemos colocar como valor de entrada.
        int qtd = 11;
    // int indx = INDEX DO ELEMENTO A SER TESTADO E VERIFICADO. --> temos que entender o que precisaremos fazer. se vao ser varios ou soment 1 elemento
        int indx = 78;
        int result = algoritmoKNN( cmds, qtd, indx );
        
        if( result == IRIS_SETOSA ) {
            printf(" index %d é IRIS SETOSA \n", indx);
        } else if( result == IRIS_VERSICOLOUR ) {
            printf(" index %d é IRIS_VERSICOLOUR \n", indx);
        } else if( result == IRIS_VIRGINICA ) {
            printf(" index %d é IRIS_VIRGINICA \n", indx);
        }
    }
    
    // Printa valores lidos:
    //printaArquivo( cmds );

    free(cmds);
    fclose(f);
    return 0;
}

void printaArquivo( infArq *cmds ) {
    for( int aux = 0; aux < 150; aux++ ) {
        printf( "%f,%f,%f,%f,", (cmds[aux].sepalLength), (cmds[aux].sepalWidth), (cmds[aux].petalLength), (cmds[aux].petalWidth));
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

    while( fscanf (f, "%f,%f,%f,%f,%s\n", &(cmds[aux].sepalLength), &(cmds[aux].sepalWidth), &(cmds[aux].petalLength), &(cmds[aux].petalWidth), tipo) != EOF ){
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

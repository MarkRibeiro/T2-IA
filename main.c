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

    infArq *cmds = (infArq*) malloc(150 * sizeof(infArq));

    atribuindoInfosArquivo( cmds, f);

    free(cmds);
    fclose(f);
    return 0;
}

int contains( char *string, char *substring ) {
    if(strstr(string, substring) != NULL) {
        return 1;
    } else {
        return 0;
    }
}

 
void atribuindoInfosArquivo( infArq *cmds, FILE *f ) {
    char linha[50];
    char tipo[20];
    int aux = 0;

    while( fscanf (f, "%f,%f,%f,%f,%s\n", &(cmds[aux].sepalLength), &(cmds[aux].sepalWidth), &(cmds[aux].petalLength), &(cmds[aux].petalWidth), tipo) != EOF ){
        if(strcmp(tipo,"Iris-setosa") == 0){
            cmds[aux].tipo = IRIS_SETOSA;
        } else if(strcmp(tipo,"Iris-versicolor") == 0) {
            cmds[aux].tipo = IRIS_VERSICOLOUR;                    
        } else if(strcmp(tipo,"Iris-virginica") == 0) {
            cmds[aux].tipo = IRIS_VIRGINICA;
        } else {
            printf("Erro na atribuicao do tipo\n");
        }
        aux++;
    }
}

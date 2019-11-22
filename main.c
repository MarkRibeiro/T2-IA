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
    //Atribuindo infos do arquivo
    atribuindoInfosArquivo( cmds, f);
    for( int aux = 0; aux < 150; aux++ ) {
        printf( "%f,%f,%f,%f\n", (cmds[aux].sepalLength), (cmds[aux].sepalWidth), (cmds[aux].petalLength), (cmds[aux].petalWidth));
    }

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
    int pos[4];
    char tipo[20];
    int aux = 0;

    while( fscanf (f, "%f,%f,%f,%f,%s\n", &(cmds[aux].sepalLength), &(cmds[aux].sepalWidth), &(cmds[aux].petalLength), &(cmds[aux].petalWidth), tipo) != EOF ){
        aux++;
    }
}

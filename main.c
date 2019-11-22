#include"main.h"

int main( int argc, char *argv[ ] ) {
    int algoritmo;
    FILE *f = fopen("iris.data", "r") ;

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
    
    infArq *cmds = (infArq*) malloc(149 * sizeof(infArq));
    //cmds->sepalLength = (float) malloc(sizeof(float));
    //cmds->sepalWidth = (float) malloc(sizeof(float));
    //cmds->petalLength = (float) malloc(sizeof(float));
    //cmds->petalWidth = (float) malloc(sizeof(float));
    //cmds->tipo = (int) malloc(sizeof(int));

    //Atribuindo infos do arquivo
    atribuindoInfosArquivo(&cmds, f);
    // Imprimir Dados de estrutura
    /*
    Solucao *sol;
    if( algoritmo == ALGORITMO_GENETICO ) {
        sol = algoritmoGenetico(cmds->edgeSection, cmds->dimension );
        printf("Solucao:\n=>distancia: %d\n=>cidades:", sol->distancia);
        for( int i = 0; i < cmds->dimension; i++ ) {
            printf(" %d ", sol->cidades[i]);
        }
        printf("\n");
    } else if( algoritmo == SIMULATED_ANNEALING ){
        sol = simulatedAnnealing( cmds->edgeSection, cmds->dimension );
        printf("Solucao:\n=>distancia: %d\n=>cidades:", sol[0].distancia);
        for( int i = 0; i < cmds->dimension; i++ ) {
            printf(" %d ", sol[0].cidades[i]);
        }
        printf("\n");
    }
    escreveArquivo( sol, &cmds, algoritmo );
    free(sol);
    */
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

 
void atribuindoInfosArquivo( infArq **cmds, FILE *f ) {
    char linha[50];
    int pos[4];
    char tipo[20];
    int aux = 0;

    while( fscanf (f, "%f,%f,%f,%f,%s\n", &cmds[aux]->sepalLength, &cmds[aux]->sepalWidth, &cmds[aux]->petalLength, &cmds[aux]->petalWidth, tipo) != EOF ){
        aux++;
    }

    printf("%f\n",  cmds[148]->sepalLength);

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmoKNN.h"

/************************************
*       Enum Algoritmo
*   -> Implementada no intuito de numerar os possíveis algoritmos, e assim facilitar o entendimento do código.
* 
*   Valores:
*       KNN = 0,
*       ADD = 1 
* 
*************************************/

enum Algoritmo {
    KNN,
    ADD
};

/* 
* contains
*  Checa se substring está contida na string
* 
*  método:
*       Percorre string buscando por ocorrencias de substring. 
* 
*  Parametros:
*       char *string -> string principal a ser checada 
*       char *substring -> string a ser buscada na string principal
*  
*  Retorno:
*       Retorna 1 caso a substring esteja presente na string e zero
*       caso contrário.
*/

int contains( char *string, char *substring );

/* 
* atribuindoInfosArquivo
*  Responsável por armazenar em memória as informações do arquivo de entrada
* 
*  método:
*       Recebe o arquivo inputado pelo usuário, e em seguida aloca uma estrutura
*       infArq para guardar toda as informações fornecidas pelo arquivo.
* 
*  Parametros:
*       infArq **cmds -> Ponteiro para estrutura de informações do arquivo 
*       de entrada
*       FILE *f -> Ponteiro para arquivo de entrada enviado pelo usuário
*  
*/

void atribuindoInfosArquivo( infArq *cmds, FILE *f );

/* 
* printaArquivo
*  Responsável por imprimir dados lidos do arquivo de banco de dados.
* 
*  método:
*       Recebe um ponteiro para a lista de campos lidos e o número de elementos a ser imprimido.
*       Imprime todos os dados especificados.
* 
*  Parametros:
*       infArq *cmds -> Ponteiro para estrutura de informações do arquivo 
*       de entrada
*       int eleNum -> Inteiro que representa o tamanho do ponteiro de informação do arquivo.
*  
*/

void printaArquivo( infArq *cmds, int eleNum );

/* 
* embaralhar
*  Responsável por emabaralhar um vetor. Especificamente nesse caso o vetor de elementos para diferentes
*  conjuntos fossem testados a cada execução.
* 
*  método:
*       Recebe um ponteiro e seu tamanho. A cada elemento gera outro aleatório e faz a substituição desse para outro.
*       Formando assim, um ponteiro "único" a cada execução.
* 
*  Parametros:
*       infArq *vet -> Ponteiro para estrutura de informações do arquivo 
*       de entrada
*       int vetSize -> Inteiro que representa o tamanho do ponteiro de informação do arquivo.
*  
*/

int embaralhar(infArq *vet, int vetSize);

/* 
* aviso
*  Exibe uma mensagem de erro quando chamada
* 
*  método:
*       Usa printf para fazer o display da mensagem no terminal 
* 
*/

void aviso();

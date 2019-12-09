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

void printaArquivo( infArq *cmds, int eleNum );

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

#include "algoritmoADD.h"

/* 
* distanciasDados
*  Responsável por calcular as distancias entre dois dados, levando em conta uma combinação de atributos possíveis
* 
*  método:
*       Recebe os atributos de dois dados diferentes, e a partir de uma string de inteiros decide quais desses atributos
*       usará para calcular a distancia euclidiana entre esses dois elementos no gráfico de soluções.
* 
*  Parametros:
*       infArq d1 -> Estrutra do Elemento 1.
*       infArq d2 -> Estrutra do Elemento 1.
*       int *combinacao -> Ponteiro de inteiros que indica quais atributos serão ser levandos em conta na soma da distancia.
*       int tamCombinacao -> Tamanho do vetor de combinacao.
*  Retorno:
*       Retorna o valor da distancia entre os elementos.
*/

double distanciaDados( infArq d1, infArq d2, int *combinacao, int tamCombinacao );

/* 
* dadosMaisProximos
*  Responsável por retornar um vetor dos K dados mais próximos de um elemento escolhido.
* 
*  método:
*       Recebe o index de um dado e um ponteiro para todos os elementos. Utiliza as entradas qtd e qtdElemTreinamento parâmetro de 
*       tamanho para preencher o vetor de retorno. qtd será o tamanho do vetor de retorno, e qtdElemTreinamento é o index do ultimo
*       elemento a ser usado para treino na lista todos. Após calcular os elementos mais próximos de index, retorna o ponteiro.
* 
*  Parametros:
*       int dado -> Index do elemento na lista de elementos.
*       infArq *todos -> Lista de todos os elementos do banco de dados.
*       int qtd -> Inteiro que representa o número de elementos mais próximos a serem encontrados.
*       int qtdElemTreinamento -> Inteiro que representa o index do último elemento a ser considerado de treinamento.
*       int *combinacao -> Ponteiro de inteiros que indica quais atributos serão ser levandos em conta na soma da distancia.
*       int tamCombinacao -> Tamanho do vetor de combinacao.
*  
*  Retorno:
*       Retorna ponteiro de elementos mais próximos.
*/

int *dadosMaisProximos( int dado, infArq *todos, int qtd, int qtdElemTreinamento, int *combinacao, int tamCombinacao );

/* 
* algoritmoKNN
*  Responsável por retornar a classificação do elemento escolhido.
* 
*  método:
*       Chama a função dadosPróximos para um elemento idx e define a classificação desse mesmo baseado na lista dos elementos
*       mais próximos desse.
* 
*  Parametros:
*       infArq *todos -> Lista de todos os elementos do banco de dados.
*       int qtdElem -> Inteiro que representa o número de elementos mais próximos a serem encontrados.
*       int qtdElemTreinamento -> Inteiro que representa o index do último elemento a ser considerado de treinamento.
*       int indx -> Inteiro que representa o indx do elemento a ser retornado o tipo.
*       int debug -> Inteiro para ligar e desligar prints de estudo.
*       int *combinacao -> Ponteiro de inteiros que indica quais atributos serão ser levandos em conta na soma da distancia.
*       int tamCombinacao -> Tamanho do vetor de combinacao.
*  
*  Retorno:
*       Retorna o inteiro que representa a classificação do elemento
*/

int algoritmoKNN( infArq *todos, int qtdElem, int qtdElemTreinamento, int idx, int debug, int *combinacao, int tamCombinacao );

/* 
* preencheComInt
*  Responsável por preencher um array com inteiros de valor especificado.
* 
*  método:
*       Recebe o valor a ser atribuido a um vetor de inteiros. Preenche todos os campos com esse valor.
* 
*  Parametros:
*       int *indexDosProximos -> Ponteiro a ser preenchido com os dados especificados em valor
*       int tam -> Inteiro que representa o tamanho do ponteiro.
*       int valor -> Inteiro que representa o conteúdo a ser adicionado nos campos do ponteiro.
*  
*/

void preencheComInt( int *indexDosProximos, int tam, int valor );

/* 
* preencheComDouble
*  Responsável por preencher um array com double de valor especificado.
* 
*  método:
*       Recebe o valor a ser atribuido a um vetor de double. Preenche todos os campos com esse valor.
* 
*  Parametros:
*       double *indexDosProximos -> Ponteiro a ser preenchido com os dados especificados em valor
*       int tam -> Inteiro que representa o tamanho do ponteiro.
*       double valor -> Double que representa o conteúdo a ser adicionado nos campos do ponteiro.
*  
*/

void preencheComDouble( double *indexDosProximos, int tam, double valor );

/* 
* retornaIndexMaior
*  Responsável por retornar o index do elemento de conteúdo de maior valor em um ponteiro.
* 
*  método:
*       Recebe um ponteiro e o seu tamanho. Busca nesse mesmo qual é o elemento de maior valor e retona seu índice.
* 
*  Parametros:
*       double *distanciaDosProximos -> Ponteiro que representa o vetor a ser buscado o indice de maior elemento.
*       int qtd -> Inteiro que representa o tamanho do ponteiro.
* 
*  Retorno:
*       Retorna o inteiro que representa o index do maior elemento de maior valor do ponteiro. 
*/

int retornaIndexMaior( double *distanciaDosProximos, int qtd );

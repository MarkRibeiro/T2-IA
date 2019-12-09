#include "InfoArquivo.h"


/* 
* algoritmoADD
*  Responsável por retornar a classificação do elemento escolhido.
* 
*  método:
*       Recebe um elemento que devera ser classificado e por meio de ifs preestabelecidos pelas árvores de decisão geradas pelo weka decide 
*       qual o tipo do elemento. O algoritmo toma decisões diferentes baseado na quantidade de atributos e proporção que recebe.
* 
*  Parametros:
*       infArq elem -> Elemento cujo o tipo deseja ser adivinhado.
*       int attNum -> Inteiro que representa o número de atributos a serem levados em conta.
*       int prop -> Inteiro que representa a proporção de elementos a serem lidos no arquivo.
*
*  Retorno:
*       Retorna 0 caso o tipo do elemento seja setosa, 1 caso o tipo do elemento seja versicolour e 2 caso o tipo do elemento seja virginica 
*/

int algoritmoADD( infArq elem, int attNum, int prop );

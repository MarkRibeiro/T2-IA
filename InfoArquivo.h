#include "stdio.h"

/************************************
*       Enum TIPOS
*   -> Implementada no intuito de numerar os possíveis tipos/classes das flores, e assim facilitar o entendimento do código.
* 
*   Valores:
*    	IRIS_SETOSA = 0,
*    	IRIS_VERSICOLOUR = 1,
*    	IRIS_VIRGINICA = 2
* 
*************************************/

enum TIPOS {
    IRIS_SETOSA ,
    IRIS_VERSICOLOUR ,
    IRIS_VIRGINICA
};

/************************************
*       Enum PROP
*   -> Implementada no intuito de numerar as possíveis proporçoes dos arquivos, e assim facilitar o entendimento do código.
* 
*   Valores:
*		UM_TERCO = 0,
*		DOIS_TERCOS = 1,
*		INTEIRO = 2
* 
*************************************/

enum PROP {
	UM_TERCO ,
	DOIS_TERCOS ,
	INTEIRO
};

/************************************
*       Estrutura infoArquivo
*   -> Implementada para armazenar em memória as informações provenientes do arquivo.
* 
*   Campos:
*       1. Sepal Length  =>  sepal length
*       2. Sepal Width   =>  sepal width
*       3. Petal Length  =>  petal length
*       4. Petal Width   =>  petal width
*		5. Tipo          =>	 class 
* 
*   Estrutura escolhida para o armazenamento dos dados foi uma vetor.
* 
*************************************/

struct infoArquivo {
	double sepalLength;
	double sepalWidth;
	double petalLength;
	double petalWidth;
	int tipo;
}; typedef struct infoArquivo infArq;

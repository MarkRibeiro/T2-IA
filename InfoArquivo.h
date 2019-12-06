#include "stdio.h"

enum TIPOS {
    IRIS_SETOSA ,
    IRIS_VERSICOLOUR ,
    IRIS_VIRGINICA
};
enum PROP {
	UM_TERCO ,
	DOIS_TERCOS ,
	INTEIRO
};

struct infoArquivo {
	double sepalLength;
	double sepalWidth;
	double petalLength;
	double petalWidth;
	int tipo;
}; typedef struct infoArquivo infArq;

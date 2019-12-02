#include "stdio.h"

enum TIPOS {
    IRIS_SETOSA ,
    IRIS_VERSICOLOUR ,
    IRIS_VIRGINICA
};

struct infoArquivo {
	float sepalLength;
	float sepalWidth;
	float petalLength;
	float petalWidth;
	int tipo;
}; typedef struct infoArquivo infArq;

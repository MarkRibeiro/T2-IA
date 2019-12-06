#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmoADD.h"

/*  NUMERO DE TIPOS:
 *    0 Iris Setosa
 *    1 Iris Versicolour
 *    2 Iris Virginica
 *
 ************************/

int DEBUG;

/* estrutura.
 * 
 * Dado {
 * 
	float sepalLength;
	float sepalWidth;
	float petalLength;
	float petalWidth;
    int tipo;
 * }
 * 
 * 
 */

int algoritmoADD( infArq elem, int attNum ) {
	if(attNum == 1){
		if( elem.petalWidth <= 0.6 )
			return 0;
		else if( elem.petalWidth <= 1.7 )
			return 1;
		else 
			return 2;
	} 

	if(attNum == 2) {
		if( elem.petalWidth <= 0.6 )
			return 0;
		else if(( elem.petalWidth <= 1.7 && elem.petalWidth > 1.5 && elem.petalLength > 4.9) || (elem.petalWidth <= 1.7 && elem.petalLength <= 4.9 ))
			return 1;
		else 
			return 2;
	}

}
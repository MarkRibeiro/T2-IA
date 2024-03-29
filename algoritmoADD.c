#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmoADD.h"

int DEBUG;

int algoritmoADD( infArq elem, int attNum, int prop ) {
	if(prop == UM_TERCO)
	{
		if(attNum == 1){
			if( elem.petalWidth <= 0.4 )
				return 0;
			else if( elem.petalWidth <= 1.7 )
				return 1;
			else 
				return 2;
		} 

		if(attNum == 2) {
			if( elem.petalWidth <= 0.4 )
				return 0;
			else if( elem.petalWidth <= 1.7 && elem.petalLength <= 5.0) 
				return 1;
			else 
				return 2;
		}
	}

	if(prop == DOIS_TERCOS)
	{
		if(attNum == 1){
			if( elem.petalWidth <= 0.5 )
				return 0;
			else if( elem.petalWidth <= 1.7 )
				return 1;
			else 
				return 2;
		} 

		if(attNum == 2) {
			if( elem.petalWidth <= 0.5 )
				return 0;
			else if( elem.petalWidth <= 1.7 && elem.petalLength <= 5.0) 
				return 1;
			else 
				return 2;
		}
	}

	if(prop == INTEIRO)
	{
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
}

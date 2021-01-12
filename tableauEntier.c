/*
Author: Abida Hassan
Filier: SDAD
*/
#include<stdio.h>
#include<stdlib.h>
int* tableauEntier(int N)
{
	
	int *T;
	T = (int*) malloc(N*sizeof(int));
	if(T == NULL)
          {
		printf("tableauEntier: pas assez de memoire\n");
		exit(-1);
	  }
	
	return T - 1;
}

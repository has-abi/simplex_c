/*
Author: Abida Hassan
Filier: SDAD
*/
#include<stdio.h>
#include<stdlib.h>
int posMinPositifTabReel(double *T,int N)
{
	int i,pos;
	double min;
	int posPremierPositif;
	i = 1;
	while(i <= N && T[i] <0)
		i++;
	
	posPremierPositif = i;
	
	if(posPremierPositif > N)
          {
		printf("Solution non bornée\n");
		exit(-1);
	  }
	
	min = T[posPremierPositif];
	pos = posPremierPositif;
	
	for(i = pos + 1;i <= N;i++)
		if(T[i]>=0 && T[i]<min)
                  {
			min = T[i];
			pos = i;
		  }
	
	return pos;	
}

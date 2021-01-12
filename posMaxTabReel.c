/*
Author: Abida Hassan
Filier: SDAD
*/
int posMaxTabReel(double *T,int N){
	int i,pos;
	double max;
	max = T[1];
	pos = 1;
	for(i = 2;i<=N;i++){
		if(max<T[i]){
			max = T[i];
			pos = i;
		}
	}	
	return pos;
}

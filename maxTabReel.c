/*
Author: Abida Hassan
Filier: SDAD
*/
double maxTabReel(double *T,int N)
{
	int i;
	double max;
	max = T[1];
	for(i = 2;i<=N;i++)
	   if(max<T[i])
             max = T[i];
	return max;
}

/*
Author: Abida Hassan
Filier: SDAD
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	
  double* tableauReel(int N);
  int* tableauEntier(int N);
  double** matriceReelle(int L,int C);
  void remplirMatriceReelle(double **A, int L,int C,FILE *pfichier);
  void remplirTableauReel(double *T, int N,FILE *pfichier);
  void afficherMatriceReelle(double **A,int L,int C);
  void afficherTableauReel(double *T,int N);
  void afficherTableauEntier(int *T,int N);
  void libererTableauReel(double *T);
  void libererMatriceReelle(double **A,int L);
  double maxTabReel(double *T,int N);
  int posMaxTabReel(double *T,int N);
  int posMinPositifTabReel(double *T,int N);
  //nombre de contraintes
  int m;
  //nombre de variable de décision
  int n;
  //pointeur sur le ficher donnee.txt
  FILE *pFichier;
  //vecteur reel de taille n ( vecteur solution x)
  double *x; 	
  //vecteur reel de taille m
  double* rapport;
  //vecteur entier de base de taille m 
  int* J;
  //la matrice A de taille (m*n)
  double** A;
  //vecteur C de taille n
  double* c;
  //vecteur b de taille m
	double* b;
  //le max de la fonction objective
  double maxC;
  double MAXIMUM, coef;
  //les indices i et j
  int i,j;
  int indiceE,indiceS;
  double pivot;
  double cIndiceE;
  pFichier = fopen("donnee.txt","r");	
  if (pFichier == NULL)
     {
       	printf("Erreur dans l\'overture du fichier!");
       	exit(1);
     }
   	
   		
   fscanf(pFichier,"%d", &n);
   fscanf(pFichier,"%d", &m);
	
   //réserver l'espace mémoire
   A = matriceReelle(m,n);
   b = tableauReel(m);
   c = tableauReel(n);
   x = tableauReel(n);
	
   //remplir les tableaux
   remplirMatriceReelle(A,m,n,pFichier);
   remplirTableauReel(b,m,pFichier);
   remplirTableauReel(c,n,pFichier);
	
  //nombre de contrainte et d'inégalités
   printf("nombre de contraintes = %d nombre de variables de decision = %d \n",m,n);
  //afficher la matrice 
   printf("la matrice A\n");
   afficherMatriceReelle(A,m,n);
	
   //afficher le vecteur b
   printf("\n le vecteur b:\n");
   afficherTableauReel(b,m);
	
   //afficher le vecteur c
   printf("\n le vecteur c:\n");
   afficherTableauReel(c,n);
	
   //réserver l'espace mémoire pour rapport
   rapport = tableauReel(m);
	
		
   //réserver l'espace mémoire pour le vecteur J
   J = tableauEntier(m);
   
   //début du simplex
   //remplir J
   for(i = 1;i<=m;i++)
      J[i] = n - m + i;
	
   maxC = maxTabReel( c,n);
   MAXIMUM = 0;
   while(maxC > 0)
        {
	  indiceE = posMaxTabReel(c,n);
	  printf("indice d\'entree = %d\n",indiceE);
	  for(i = 1;i<=m;i++)
             {
		if(A[i][indiceE] != 0)
		  rapport[i] = b[i]/A[i][indiceE];	
		else
		  rapport[i] = -1;
	     }
	
	
	  indiceS = posMinPositifTabReel(rapport,m);
	  printf("indice de sortie = %d\n",indiceS);
	
          // Mise à jour du tableau J ( Base )
	  J[indiceS] = indiceE;
	
	  pivot = A[indiceS][indiceE];
	  printf("Le pivot = %f\n",pivot);
	  if(pivot != 1)
            {
	      for(j = 1;j<=n;j++)
		 A[indiceS][j] /= pivot;
			
              b[indiceS] /= pivot;	
	    }
	
	//les combinaisons linéaires des lignes avec la ligne du pivot
	 for(i = 1;i<=m;i++)
       
	    if(i != indiceS)
	      { 
               coef = A[i][indiceE];
               for(j = 1;j<=n;j++)
                  A[i][j] -= coef*A[indiceS][j]; 
               b[i]-=coef*b[indiceS];
               					
	      }
	
	 cIndiceE = c[indiceE];	 	 
	 for(j = 1;j<=n;j++)
	    c[j] = c[j] - cIndiceE*A[indiceS][j];
	 
	 
	//mise à jour du max
	MAXIMUM -= cIndiceE*b[indiceS];
	
	//detail des operations de chaque étape
	printf("\nla matrice A\n");
	afficherMatriceReelle(A,m,n);
	
	
	printf("\nla vecteur B\n");
	afficherTableauReel(b,m);
	printf("\nla vecteur C\n");
	afficherTableauReel(c,n);
	printf("\n-max = %lf",MAXIMUM);
	
	maxC = maxTabReel( c,n);
	
       } 
	
	//afficher la solution
       printf("\n----------------------------------\n");	
       printf("\nSolution\n");
       printf("MAXIMUM = %lf\n",-MAXIMUM);
       printf("la vecteur b\n");
       afficherTableauReel(b,m);
       printf("la vecteur J\n");
       afficherTableauEntier(J,m);
       printf("\n");	
      
       for ( i=1 ; i <= n ; i++ )
           x[i] = 0;
       for( i= 1; i<= m ; i++ )
          x[J[i]]= b[i];

       printf("la vecteur solution\n");
       afficherTableauReel(x,n);
	//fermer les fichier et libération de la mémoire			   	
   	fclose(pFichier); 
 	/* libererTableauReel(b);
 	libererTableauReel(c);
 	libererTableauReel(rapport);
 	
 	libererMatriceReelle(A,m);	
*/
   	return 0;
 		
}

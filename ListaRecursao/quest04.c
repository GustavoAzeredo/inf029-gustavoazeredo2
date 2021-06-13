#include<stdio.h>

int SomaElementosVetores();

int main(int argc, char const *argv[])
{
	int vetor[]={1,2,5,8,6,4,7,3,5,3,7,3,4,3,1};
	int tamanhovetor = 14, soma = 0;

		soma = SomaElementosVetores(vetor, tamanhovetor);

			printf("%d\n", soma);

	return 0;
}

int SomaElementosVetores(int v[], int n){

	int s = 0;

		if (n<0)
			return 0;

		else
			s = v[n] + SomaElementosVetores(v,n-1);

	return s;
}
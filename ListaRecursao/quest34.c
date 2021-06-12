#include<stdio.h>

int ImprimeSerie();

int main(int argc, char const *argv[])
{
	int i = 4, j = 35, k = 3;

		ImprimeSerie(i,j,k);

			printf("\n");

	return 0;
}

int ImprimeSerie(int i, int j, int k){

	int n = i;

		if (n>j)
			return 0;

		else
			printf("%d ", n);

				ImprimeSerie(i+k,j,k);

	return 0;
}
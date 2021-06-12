#include<stdio.h>

int SomaSerie();

int main(int argc, char const *argv[])
{
	int i = 4, j = 35, k = 3, soma = 0;

		soma = SomaSerie(i,j,k);

			printf("%d\n", soma);

	return 0;
}

int SomaSerie(int i, int j, int k){

	int n = i, s = 0;

		if (n>j)
			return 0;

		else
			s = n + SomaSerie(i+k,j,k);

	return s;
}
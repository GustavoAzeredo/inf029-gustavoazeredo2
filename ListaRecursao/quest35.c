#include<stdio.h>

int ConverteParaBinario();

int main(int argc, char const *argv[])
{
	int n = 35;

		ConverteParaBinario(n);

			printf("\n");

	return 0;
}

int ConverteParaBinario(int n){

	int b = n%2;

		if (n==0)
			return 0;

			ConverteParaBinario(n/2);

				printf("%d", b);

	return b;
}
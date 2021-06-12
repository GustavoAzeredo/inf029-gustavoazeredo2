#include<stdio.h>

int exponencial();

int main(int argc, char const *argv[]){

	int k, n, p = 0, valor = 0;

		printf("Digite o valor de k: ");
		scanf("%d",&k);
		printf("\nDigite o valor de n: ");
		scanf("%d",&n);

			valor = exponencial(k,n,p);

				printf("\n");
				printf("%d\n", valor);

	return 0;
}

int exponencial(int a, int b, int p){

	int v;

		if (p==b)
			return 1;

		else{
			p++;
			v = a * exponencial(a,b,p);
		}
		
	return v;
}
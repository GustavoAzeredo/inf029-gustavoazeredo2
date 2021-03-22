#include<stdio.h>
#include "notas.h"

int main(int argc, char const *argv[])
{
	float status, n1, n2, n3;

	printf("Digite a primeira nota: \n");
	scanf("%f",&n1);
	printf("Digite a segunda nota: \n");
	scanf("%f",&n2);
	printf("Digite a terceira nota: \n");
	scanf("%f",&n3);

	status = notas(n1,n2,n3);
	if (status>=7)
	{
		printf("APROVADO(A) - Média: %f",status);
	}
	else
	{
		printf("REPROVADO(A) - Média: %f",status);
	}
	return 0;
}
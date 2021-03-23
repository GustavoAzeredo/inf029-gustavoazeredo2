#include<stdio.h>

/*Função 'soma' que calcula a soma de 
dois números*/

float soma(float a, float b)
{
	float val;
	val = (a + b);
	return val;
}

/*Função main que lê e imprime dois números*/

int main()
{
	float a, b, res;
	printf("Digite o primeiro número\n");
	scanf("%f",&a);
	printf("Digite o segundo número\n");
	scanf("%f",&b);

	res = soma(a,b);
	printf("A soma de %f e %f é: %f\n",a,b,res);
	return 0;
}
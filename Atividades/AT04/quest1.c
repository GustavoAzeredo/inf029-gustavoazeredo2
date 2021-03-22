#include<stdio.h>

float soma(float a, float b)
{
	float val;
	val = (a + b);
	return val;
}
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
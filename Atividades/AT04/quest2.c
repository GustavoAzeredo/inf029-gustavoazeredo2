#include<stdio.h>

float subtrai(float a, float b, float c)
{
	float resto;
	resto = (a - b - c);
	return resto;
}
int main(int argc, char const *argv[])
{
	float a, b, c, res;
	printf("Digite o primeiro número: \n");
	scanf("%f",&a);
	printf("Digite o segundo número: \n");
	scanf("%f",&b);
	printf("Digite o terceiro número: \n");
	scanf("%f",&c);

	res = subtrai(a,b,c);
	printf("(%f - %f - %f) = %f\n",a,b,c,res);
	return 0;
}
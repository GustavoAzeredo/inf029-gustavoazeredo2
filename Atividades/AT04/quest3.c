#include<stdio.h>

/*Função 'fat' recebe um número, verifica se pode ser calculado
seu fatorial, se possível calcula seu fatorial, caso contrário
manda uma menssagem de erro.*/

int fat(int a)
{
	int val=1, i=1;
	if (a<=-1||a%2!=0)
	{
		printf("ERRO: Digite um número inteiro e positivo!\n");
	}
	if (a==0||a==1)
	{
		val = 1;
	}
	if (a>=2)
	{
		do
		{
			val = val*i;
			i++;
		}
		while(i<=a);
	}
	return val;
}

/*Função main que lê e imprime o númro.*/

int main(int argc, char const *argv[])
{
	int b, resp;
	printf("Digite o número: \n");
	scanf("%d",&b);
	resp = fat(b);
	if (b>=0)
	{
		printf("O fatorial de %d é: %d \n",b,resp);
	}
	return 0;
}
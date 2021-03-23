#include <stdio.h>
#include <stdlib.h>

/*Definição da struct e transformação (typedef) da 
struct em um tipo-de-dados (novo).*/

typedef struct 
	{
		float n1;
		float n2;
		float n3;
		float n4;
	}novo;
	novo num;

/*Função 'ler4numeros' que lê os quatro números.*/

novo ler4numeros(float a, float b, float c, float d)
{
	novo n;

	printf("Digite o primeiro número: \n");
	scanf("%f",&n.n1);
	printf("Digite o segundo número: \n");
	scanf("%f",&n.n2);
	printf("Digite o terceiro número: \n");
	scanf("%f",&n.n3);
	printf("Digite o quarto número: \n");
	scanf("%f",&n.n4);
	return n;
}

/*Função main que imprime os quatro números*/

int main()
{
	float n1,n2,n3,n4;
	
	novo num = ler4numeros(n1,n2,n3,n4);

	printf("%f, ",num.n1);
	printf("%f, ",num.n2);
	printf("%f, ",num.n3);
	printf("%f",num.n4);
	return 0;
}
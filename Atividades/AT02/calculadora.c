#include<stdio.h>

int main()
{
	float valor1, valor2, resultado;
	int op;

	printf("Digite o primeiro número\n");
	scanf("%f",&valor1);
	printf("Digite o segundo número\n");
	scanf("%f",&valor2);

	printf("Agora escolha a operação que deseja:\n\n 0 - sair\n\n 1 - Somar\n\n 2 - Subtrair\n\n 3 - Multiplicar\n\n 4 - Dividir\n\n");
	scanf("%d",&op);

	if(op==0)
	{
		printf("Sair\n\n");
	}
		if(op==1)
		{
			resultado = (valor1 + valor2);
			printf("Soma = %.2f\n\n",resultado);
		}
			if(op==2)
			{
				resultado = (valor1 - valor2);
				printf("Subtração = %.2f\n\n",resultado);
			}
				if(op==3)
				{
					resultado = (valor1 * valor2);
					printf("Multiplicação = %.2f\n\n",resultado);
				}
					if(op==4)
					{
						resultado = (valor1/valor2);
						printf("Divisão = %.2f\n\n",resultado);
					}
						if(op>4||op<0)
						{
							printf("ERRO: digite um operador válido\n\n");
						}

}
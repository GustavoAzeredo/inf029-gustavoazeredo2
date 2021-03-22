#include<stdio.h>

/*Função que ler os três números digitados 
pelo usuário e os coloca em um vetor.*/
int l3n(int vet[], int n)
{
	n=3;
	int i=0;
	do
	{
		printf("Digite um número: \n");
		scanf("%d",&vet[i]);
		i++;
	} while (i<n);
}
/*Inprimindo os números digitados.*/
int main(int argc, char const *argv[])
{
	int v[3], a;
	
	l3n(v,a);

	for (int j = 0; j < 3; ++j)
	 {
	 	if (j==0)
	 	{
	 		printf("[%d, ",v[j]);
	 	}
	 	if (j==2)
	 	{
	 		printf("%d]",v[j]);
	 	}
	 	if (j==1)
	 	{
	 		printf(" %d, ",v[j]);
	 	}
	 } 
	return 0;
}
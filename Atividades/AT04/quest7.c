#include <stdio.h>
#include <stdlib.h>

/*Definição da struct que vai receber as palavras.*/

typedef struct 
{
	char str1[20];
	char str2[20];
	char str3[20];
}novo;
novo palavras;

/*Função 'ler 3 palavras' que lê as palavras e 
as coloca na struct.*/

novo ler3palavras(char p1[], char p2[], char p3[])
{
	novo l3p;

	printf("Escreva a primeira palavra: \n");
	scanf("%s",&l3p.str1);
	printf("Escreva a segunda palavra: \n");
	scanf("%s",&l3p.str2);
	printf("Escreva a terceira palavra: \n");
	scanf("%s",&l3p.str3);
	return l3p;
}

/*Função 'main' que imprime as palavras.*/

int main()
{
	char word1[20];
	char word2[20];
	char word3[20];

	novo palavras = ler3palavras(word1, word2, word3);

	printf("[%s, ",palavras.str1);
	printf("%s, ",palavras.str2);
	printf("%s]",palavras.str3);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	char string1[20];
	char string2[20];
	char string3[20];
}novo;
novo palavras;

novo ler3palavras(char a[], char b[], char c[])
{
	novo l3p;

	printf("Escreva a primeira: \n");
	scanf("%s",&l3p.string1);
	printf("Escreva a primeira: \n");
	scanf("%s",&l3p.string2);
	printf("Escreva a primeira: \n");
	scanf("%s",&l3p.string3);
	return l3p;

}
int main(int argc, char const *argv[])
{
	char string1[20];
	char string2[20];
	char string3[20];

	novo palavras = ler3palavras(string1, string2, string3);

	printf("%s\n",palavras.string1);
	printf("%s\n",palavras.string2);
	printf("%s\n",palavras.string3);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	char str1[20];
	char str2[20];
	char str3[20];
}novo;
novo palavras;

novo ler3palavras(novo a, char p1[], char p2[], char p3[])
{
	novo l3p;

	printf("Escreva a primeira palavra: \n");
	scanf("%s",&l3p.str1);
	printf("Escreva a segunda palavra: \n");
	scanf("%s",&l3p.str2);
	printf("Escreva a terceira palavra: \n");
	scanf("%s",&l3p.str3);

}
int main(int argc, char const *argv[])
{
	char word1[20];
	char word2[20];
	char word3[20];

	ler3palavras(palavras, word1, word2, word3);

	printf("%s\n",palavras.str1);
	printf("%s\n",palavras.str2);
	printf("%s\n",palavras.str3);

	return 0;
}
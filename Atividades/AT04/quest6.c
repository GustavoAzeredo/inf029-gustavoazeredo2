#include <stdio.h>

char l3l(char let[])
{
	int n=3;
	for (int i = 0; i < 3; ++i)
	{
		if (i==0)
		{
			printf("\nDigite as letras: ");
			scanf("%c",&let[i]);
		}
		else
		{
			scanf("%c",&let[i]);
		}
	}
}
int main(int argc, char const *argv[])
{
	char l[3];

	l3l(l);

	for (int j = 0; j < 3; ++j)
	 {
	 	if (j==0)
	 	{
	 		printf("\n[%c, ",l[j]);
	 	}
	 	if (j==2)
	 	{
	 		printf("%c]\n\n",l[j]);
	 	}
	 	if (j==1)
	 	{
	 		printf(" %c, ",l[j]);
	 	}
	 } 
	return 0;
}
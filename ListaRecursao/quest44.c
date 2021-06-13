#include<stdio.h>

int SomaDosCubos();

int main(int argc, char const *argv[])
{

	int n = 10, valor = 0;

		valor = SomaDosCubos(n);

			printf("%d\n", valor);

	return 0;
}

int SomaDosCubos(int a)
{

	int v;

		if (a==0)
			return 0;

		else
			v = a*a*a + SomaDosCubos(a-1);
		
		
	return v;
}
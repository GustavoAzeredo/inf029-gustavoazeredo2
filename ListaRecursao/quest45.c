#include<stdio.h>

int SomaDosDigitos();

int main(int argc, char const *argv[])
{
	int n = 48352, soma = 0;

	soma = SomaDosDigitos(n);

	printf("%d\n",soma);


	return 0;
}

int SomaDosDigitos(int n){

	int s = 0;

	if (n/10==0)
		return n;

	else
		s = n%10 + SomaDosDigitos(n/10);

	return s;
}
#include <stdio.h>

int soma();

int main(int argc, char const *argv[])
{
	int N = 6, somatorio = 0;

	somatorio = soma(N);

	printf("%d\n",somatorio );

	return 0;
}

int soma(int n){

	int s;

	if (n==0)
		return 0;
	else
		s = n + soma(n-1);

	return s;
}
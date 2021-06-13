#include <stdio.h>

double Catalan();

int main(int argc, char const *argv[])
{
	double num = 10, resposta = 0;

		resposta = Catalan(num);

			printf("%.0lf\n", resposta);

	return 0;
}

double Catalan(double n)
{
	double res;

	if (n==0)
		return 1;

	else
		res = ((4*n)-2)/(n+1) * Catalan(n-1);

	return res;
}	
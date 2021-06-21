#include <stdio.h>

int fibonacci();

int main(int argc, char const *argv[])
{
	int num = 10, f = 0;

		f = fibonacci(num);

			printf("%d\n", f);


	return 0;
}

int fibonacci(int n)
{
	int f;

		if (n==1)
			return 0;

		else if (n==2||n==3)
			return 1;

		else
			f = fibonacci(n-1) + fibonacci(n-2);

	return f;
}
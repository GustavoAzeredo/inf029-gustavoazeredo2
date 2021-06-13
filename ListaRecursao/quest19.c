#include <stdio.h>
#include <math.h> // Na hora de compilar: quest19.c -o quest19 -lm.

int HiperFatorial();

int main(int argc, char const *argv[])
{
	
	int num = 4;
	long int fat = 0;

		fat = HiperFatorial(num);

			printf("%ld\n", fat);

	return 0;
}

int HiperFatorial(int n){

	int f;

	if (n<=1)
		return 1;

	else
		f = pow(n,n) * HiperFatorial(n-1);

	return f;
}
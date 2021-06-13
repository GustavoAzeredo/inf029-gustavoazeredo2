#include<stdio.h>

long int fatorialquadruplo();

int main(int argc, char const *argv[]){

	int numero = 5, num = 0;
	long int fat = 0;

		num = numero * 2;

			fat = fatorialquadruplo(num, numero);

				printf("%ld\n", fat);
		
	return 0;
}

long int fatorialquadruplo(int n, int a){

	long int f;
	
		if (n==a)
			return 1;

		else
			f = n * fatorialquadruplo(n-1,a);

	return f;
}
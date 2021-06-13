#include<stdio.h>

long int fatorial();

int main(int argc, char const *argv[]){

	int num = 20;
	long int fat = 0;

		fat = fatorial(num);

			printf("%ld\n", fat);
		
	return 0;
}

long int fatorial(int n){

	long int f;
	
		if (n==0)
			return 1;
		
		else
			f = n * fatorial(n-1);

	return f;
}
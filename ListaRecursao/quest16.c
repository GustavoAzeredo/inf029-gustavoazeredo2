#include<stdio.h>

long int fatorial();

int main(int argc, char const *argv[]){

	int num = 13;
	long int fat = 0;

		fat = fatorial(num);

			printf("%ld\n", fat);
		
	return 0;
}

long int fatorial(long int n){

	long int f;

		if (n%2==0)
			return 0;
			
		else if (n==1)
			return 1;

		else
			f = n * fatorial(n-2);

	return f;
}
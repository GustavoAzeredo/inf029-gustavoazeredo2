#include<stdio.h>

int Multip_Rec();

int main(int argc, char const *argv[]){

	int n1 = 7, n2 = 7, p = 0, valor = 0;

		valor = Multip_Rec(n1,n2,p);

			printf("\n");
			printf("%d\n", valor);

	return 0;
}

int Multip_Rec(int a, int b, int p){

	int v;

		if (p==b)
			return 0;

		else{
			p++;
			v = a + Multip_Rec(a,b,p);
		}
		
	return v;
}
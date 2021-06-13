#include <stdio.h>

int InverteElementosDoVetor();

int main(int argc, char const *argv[])
{
	int n = 100;
	int vetor[n], vetoraux[n], a = n, b = 0;

		for (int i = 0; i < n; ++i)
			vetor[i] = i+1;

			InverteElementosDoVetor(a,b,vetor,vetoraux);

				for (int i = 0; i < n; ++i)
				{
					if (i==0)
						printf("[%d,", vetoraux[i]);
					
					else if (i==n-1)
						printf("%d]", vetoraux[i]);
					
					else
						printf("%d,", vetoraux[i]);
				}

					printf("\n");
				
	return 0;
}

int InverteElementosDoVetor(int a, int b, int v[], int va[])
{

	int c = 0;

		c = v[a-1];
		va[b] = c;

			if (a<0)
				return 0;

			else
				InverteElementosDoVetor(a-1,b+1,v,va);

	return 0;
}
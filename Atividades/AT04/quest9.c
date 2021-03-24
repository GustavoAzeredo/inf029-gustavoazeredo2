#include<stdio.h>

/*Definição da struct que vai receber os dados.*/

typedef struct 
{
	char nome[20];
	int dia;
	int mes;
	int ano;
	char cpf[11];
	char sexo;
}novo;
novo dados;

/*Função 'cadastrarcliente' que lê os dados e 
os coloca na struct.*/

novo cadastrarcliente(char n[], int d, int m, int a, char c[], char s)
{
	novo cc;

	printf("Nome: \n");
	gets(cc.nome);
	printf("Digite dia, mês e ano do nascimento: \n");
	scanf("%d%d%d",&cc.dia,&cc.mes,&cc.ano);
	printf("Digite o CPF (sem separações): \n");
	scanf("%s",&cc.cpf);
	printf("Sexo: \n");
	scanf("%s",&cc.sexo);

	return cc;
}

char validarnome(char a[], char x[])
{
	int b;
	b = strlen(a);
	if (b<=20)
	{
		strcpy(x,"Nome válido!\n");
	}
	else
	{
		strcpy(x,"Nome inválido! Digite um nome com até 20 caracteres.\n");
	}

}

char validarcpf(char b[], char y[])
{
	int c;
	c = strlen(b);
	if (c==11)
	{
		strcpy(y,"CPF válido!\n");
	}
	else
	{
		strcpy(y,"CPF inválido! CPF contém 11 dígitos.\n");
	}
}

/*Função 'main' que imprime os dados.*/

int main()
{
	char name[20];
	char sex;
	int day, month, year;
	char ssn[11];

	novo dados = cadastrarcliente(name, day, month, year, ssn, sex);

		char vn[100];
		validarnome(dados.nome, vn);

		printf("%s - %s\n",dados.nome,vn);

		char vcpf[100];
		validarcpf(dados.cpf,vcpf);

		printf("%s - %s\n",dados.cpf,vcpf);




		return 0;
}
#include<stdio.h>

/*Definição da struct que vai receber os dados.*/

typedef struct 
{
	char nome[20];
	int dia;
	int mes;
	int ano;
	char cpf[15];
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
	scanf("%d%d%d",&cc.dia,&cc.mes,&cc.ano);setbuf(stdin,NULL);
	printf("Digite o CPF (apenas números): \n");
	gets(cc.cpf);
	printf("Sexo: \n");
	scanf("%c",&cc.sexo);setbuf(stdin,NULL);

	return cc;
}

/*Função 'validarnome' que valida o nome do cliente.*/

char validarnome(char a[], char x[])
{
	int b;
	b = strlen(a);
	if (b<=20)
	{
		strcpy(x,"Válido!\n");
	}
	else
	{
		strcpy(x,"Inválido! Digite um nome com até 20 caracteres.\n");
	}

}

/*Função 'validarcpf' que valida o cpf do cliente.*/

char validarcpf(char b[], char y[])
{
	int c;
	c = strlen(b);
	if (c==11)
	{
		strcpy(y,"Válido!\n");
	}
	else
	{
		strcpy(y,"Inválido! CPF contém 11 dígitos.\n");
	}
}

/*Função 'validarsexo' que valida o sexo do cliente.*/

char validarsexo(char h[], char z[])
{
	if (h=='m'||h=='M'||h=='f'||h=='F'||h=='o'||h=='O')
	{
		strcpy(z,"Válido!\n");
	}
	else
	{
		strcpy(z,"Inválido! Digite: 'm', 'n' ou 'o'.");
	}
}

/*Função 'main' que imprime os dados.*/

int main()
{
	char name[20];
	char sex;
	int day, month, year;
	char ssn[15];

	novo dados = cadastrarcliente(name, day, month, year, ssn, sex);

		char vn[100];
		validarnome(dados.nome, vn);

		printf("- Nome: %s - %s\n",dados.nome,vn);

		char vcpf[100];
		validarcpf(dados.cpf,vcpf);

		printf("- CPF: %s - %s\n",dados.cpf,vcpf);

		char vs[100];
		validarsexo(dados.sexo,vs);

		printf("- Sexo: %c - %s\n",dados.sexo,vs);


		return 0;
}
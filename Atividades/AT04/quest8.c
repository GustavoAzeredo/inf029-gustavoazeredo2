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

/*Função 'main' que imprime os dados.*/

int main()
{
	char name[20];
	char sex;
	int day, month, year;
	char ssn[15];

	novo dados = cadastrarcliente(name, day, month, year, ssn, sex);

	printf("- Nome: %s\n",dados.nome);
	printf("- Data: %d/%d/%d\n",dados.dia,dados.mes,dados.ano);
	printf("- CPF: %s\n",dados.cpf);
	printf("- Sexo: %c\n",dados.sexo);
	return 0;
}
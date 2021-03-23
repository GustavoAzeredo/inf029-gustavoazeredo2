#include<stdio.h>

/*Definição da struct que vai receber os dados.*/

typedef struct 
{
	char nome[10];
	char sobrenome[10];
	int dia;
	int mes;
	int ano;
	double cpf;
	char sexo[1];
}novo;
novo dados;

/*Função 'cadastrarcliente' que lê os dados e 
os coloca na struct.*/

novo cadastrarcliente(char n[], char sn[], int d, int m, int a, double c, char s[])
{
	novo cc;

	printf("Nome: \n");
	scanf("%s",&cc.nome);
	printf("sobrenome: \n");
	scanf("%s",&cc.sobrenome);
	printf("Digite dia, mês e ano do nascimento: \n");
	scanf("%d%d%d",&cc.dia,&cc.mes,&cc.ano);
	printf("Digite o CPF: \n");
	scanf("%lf",&cc.cpf);
	printf("Sexo: \n");
	scanf("%s",&cc.sexo);

	return cc;
}

/*Função 'main' que imprime os dados.*/

int main()
{
	char name[10];
	char lastname[10];
	char sex[5];
	int day, month, year;
	double ssn;

	novo dados = cadastrarcliente(name, lastname, day, month, year, ssn, sex);

	printf("- Nome: %s %s\n",dados.nome,dados.sobrenome);
	printf("- Data de nascimentto: %d/%d/%d\n",dados.dia,dados.mes,dados.ano);
	printf("- CPF: %.0lf\n",dados.cpf);
	printf("- Sexo: %s\n",dados.sexo);

	return 0;
}
#include <stdio.h>

/*Definição das struct de cadastro dos alunos e professores.*/

typedef struct
{
	char matricula[15];
	char nome[40];
	char sexo;
	char cpf[15];
	int dia;
	int mes;
	int ano;
}dados;

dados aluno[2000];
dados professor[50];

/*Definição da struct de cadasdtro das disciplinas.*/

typedef struct
{
	char nome[15];
	char codigo[10];
	char professor[40];
	int semestre;
}cadastro;

cadastro disciplinas[70];

/*Função de 'CadastrarDisciplina' que lê os dados das disciplinas.*/

	cadastro CadastrarDisciplina()
	{
		int opfinal, i=0, cont=1;
		cadastro dis[70];

		do
		{
			printf("Digite o nome da disciplina: \n");
			gets(dis[i].nome);setbuf(stdin,NULL);
			printf("Digite o código da disciplina: \n");
			gets(dis[i].codigo);setbuf(stdin,NULL);
			printf("Digite o nome do professor: \n");
			gets(dis[i].professor);setbuf(stdin,NULL);
			printf("Digite o semestre da disciplina: \n");
			scanf("%d",&dis[i].semestre);setbuf(stdin,NULL);
			printf("\n\nMatricular outra disciplina, digite 1\n");
			printf("Encerrar, digite 0.\n\n");
			scanf("%d",&opfinal);setbuf(stdin,NULL);
			if (opfinal==1)
			{
				i++;
				cont++;
			}
			else
			{
				if (opfinal==0)
				{
					i++;
					cont=cont;
				}
			}
		} while (i<cont);
		
		return dis[70];
	}

	/*Função de 'CadastrarAlunos' que lê os dados dos alunos.*/

		dados CadastrarAluno()
		{
			dados alu;

			printf("Digite a matrícula do aluno: \n");
			gets(alu.matricula);setbuf(stdin,NULL);
			printf("Digite o nome do aluno: \n");
			gets(alu.nome);setbuf(stdin,NULL);
			printf("Digite o sexo do aluno: \n");
			gets(alu.sexo);setbuf(stdin,NULL);
			printf("Digite o cpf do aluno: \n");
			gets(alu.cpf);setbuf(stdin,NULL);
			printf("Digite a data de nascimento do aluno: \n");
			scanf("%d%d%d",&alu.dia,&alu.mes,&alu.ano);setbuf(stdin,NULL);

			return alu;
		}

		/*Função de CadastrarProfessor', que lê os dados do professores.*/

		dados CadastrarProfessor()
		{
			dados prof;

			printf("Digite a matrícula do professor: \n");
			gets(prof.matricula);setbuf(stdin,NULL);
			printf("Digite o nome do professor: \n");
			gets(prof.nome);setbuf(stdin,NULL);
			printf("Digite o sexo do professor: \n");
			gets(prof.sexo);setbuf(stdin,NULL);
			printf("Digite o cpf do professor: \n");
			gets(prof.cpf);setbuf(stdin,NULL);
			printf("Digite a data de nascimento do professor: \n");
			scanf("%d%d%d",&prof.dia,&prof.mes,&prof.ano);setbuf(stdin,NULL);

			return prof;
		}

		/*Função 'MenuPrincipal'.*/

		int MenuPrincipal()
		{
			int escolha, a;

			printf("\nBem vindo ao sistema eletrônico da Escola Isacc Newton!\n\n");
			printf("- Digite 1: Para disciplina.\n");	
			printf("- Digite 2: Para aluno.\n");	
			printf("- Digite 3: Para professor.\n");	
			printf("- Digite 0: Para sair.\n\n");
			scanf("%d",&a);setbuf(stdin,NULL);

			escolha = a;
			return escolha;
		}

		/*Função 'MenuDisciplina'.*/

		int MenuDisciplina ()
		{
			int escolha, a;

			printf("\n- Digite 1: Para cadastrar disciplina.\n");
			printf("- Digite 0: Para voltar ao menu principal.\n\n");
			scanf("%d",&a);setbuf(stdin,NULL);

			escolha = a;
			return escolha;			
		}

		/*Função 'MenuAluno'.*/

		int MenuAluno ()
		{
			int escolha, a;

			printf("\n- Digite 1: Para cadastrar aluno.\n");
			printf("- Digite 2: Para inserir aluno em uma disciplina.\n");		
			printf("- Digite 3: Para excluir aluno de uma disciplina.\n");		
			printf("- Digite 0: Para voltar ao menu principal.\n\n");
			scanf("%d",&a);setbuf(stdin,NULL);

			escolha = a;
			return escolha;	
		}

		/*Função 'MenuProfessor'.*/

		int MenuProfessor ()
		{
			int escolha, a;

			printf("\n- Digite 1: Para cadastrar professor.\n");
			printf("- Digite 0: Para voltar ao menu principal.\n\n");
			scanf("%d",&a);setbuf(stdin,NULL);

			escolha = a;
			return escolha;	
		}
		
/*Função main*/

int main(int argc, char const *argv[])
{
	int op1, op2;

	do
	{
		op1 = MenuPrincipal();
		if (op1 == 0)
		{
			printf("\nSair!\n");
		}
		else
		{
			if (op1 == 1)
			{
				op2 = MenuDisciplina();
				if (op2 == 1)
				{
					cadastro disc = CadastrarDisciplina();
				}
				else
				{
					if (op2 != 0 && op2 >1)
					{
						printf("\nOpção Inválida!\n");
						op2 = MenuDisciplina();
					}
				}
			}
			else
			{
				if (op1 == 2)
				{
					op2 = MenuAluno();
					if (op2 == 1)
					{
						dados alun = CadastrarAluno();
					}
					else
					{
						if (op2 == 2)
						{
							/* code */
						}
						else
						{
							if (op2 == 3)
							{
								/* code */
							}
							else
							{
								if (op2 != 0 && op2 > 3)
								{
									printf("\nOpção Inválida!\n");
									op2 = MenuAluno();
								}
							}
						}
					}
				}
				else
				{
					if (op1 == 3)
					{
						op2 = MenuProfessor();
						if (op2 == 1)
						{
							dados prof = CadastrarProfessor();
						}
						else
						{
							if (op2 != 0 && op2 > 1)
							{
								printf("\nOpção Inválida!\n");
								op2 = MenuProfessor();
							}
						}
					}
					else
					{
						printf("\nOpção inválida!\n");
					}
				}
			}
		}
	} while (op2 == 0 && op1 != 0);

	return 0;
}

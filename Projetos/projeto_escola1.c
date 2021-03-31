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
	char semestre[5];
}cadastro;

cadastro disciplinas[70];

/*Função de 'CadastrarDisciplina' que lê os dados das disciplinas.*/

	cadastro InserirDisciplina()
	{
		int op3, i=0, cont=1;
		cadastro dis[70];

		do
		{
			printf("Digite o nome da disciplina: \n");
			gets(dis[i].nome);setbuf(stdin,NULL);
			printf("Digite o código da disciplina: \n");
			gets(dis[i].codigo);setbuf(stdin,NULL);
			printf("Digite o nome do professor: \n");
			gets(dis[i].professor);setbuf(stdin,NULL);
			printf("Digite o semestre da disciplina: \n\n");
			gets(dis[i].semestre);setbuf(stdin,NULL);
			printf("\n\nDigite 1: Para continuar.\n");
			printf("Digite 0: Para encerrar.\n\n");
			scanf("%d",&op3);setbuf(stdin,NULL);

			if (op3==1)
			{
				i++;
				cont++;
			}
			else
			{
				i++;
				cont=cont;
				MenuPrincipal();
			}
		} while (i<cont);
		
		return dis[70];
	}

	/*Função de 'CadastrarAlunos' que lê os dados dos alunos.*/

		dados InserirAluno()
		{
			int op3, i=0, cont=1;
			dados alu[2000];

			do
			{
				printf("Digite a matrícula do aluno: \n");
				gets(alu[i].matricula);setbuf(stdin,NULL);
				printf("Digite o nome do aluno: \n");
				gets(alu[i].nome);setbuf(stdin,NULL);
				printf("Digite o sexo do aluno: \n");
				gets(alu[i].sexo);setbuf(stdin,NULL);
				printf("Digite o cpf do aluno: \n");
				gets(alu[i].cpf);setbuf(stdin,NULL);
				printf("Digite a data de nascimento do aluno: \n");
				scanf("%d%d%d",&alu[i].dia,&alu[i].mes,&alu[i].ano);setbuf(stdin,NULL);
				printf("\n\nDigite 1: Para continuar.\n");
				printf("Digite 0: Para encerrar.\n\n");
				scanf("%d",&op3);setbuf(stdin,NULL);

				if (op3==1)
				{
					i++;
					cont++;
				}
				else
				{
					i++;
					cont=cont;
					MenuPrincipal();
				}
			} while (i<cont);

			return alu[2000];
		}

		/*Função de CadastrarProfessor', que lê os dados do professores.*/

		dados InserirProfessor()
		{
			int op3, i=0, cont=1;
			dados prof[50];

			do
			{
				printf("Digite a matrícula do professor: \n");
				gets(prof[i].matricula);setbuf(stdin,NULL);
				printf("Digite o nome do professor: \n");
				gets(prof[i].nome);setbuf(stdin,NULL);
				printf("Digite o sexo do professor: \n");
				gets(prof[i].sexo);setbuf(stdin,NULL);
				printf("Digite o cpf do professor: \n");
				gets(prof[i].cpf);setbuf(stdin,NULL);
				printf("Digite a data de nascimento do professor: \n");
				scanf("%d%d%d",&prof[i].dia,&prof[i].mes,&prof[i].ano);setbuf(stdin,NULL);
				printf("\n\nDigite 1: Para continuar.\n");
				printf("Digite 0: Para encerrar.\n\n");
				scanf("%d",&op3);setbuf(stdin,NULL);
				
				if (op3==1)
				{
					i++;
					cont++;
				}
				else
				{
					i++;
					cont=cont;
					MenuPrincipal();
				}
			} while (i<cont);

			return prof[50];
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

		int MenuDisciplina()
		{
			int escolha, a;

			printf("\n- Digite 1: Para inserir disciplina.\n");
			printf("\n- Digite 2: Para excluir disciplina.\n");
			printf("\n- Digite 3: Para atualizar disciplina.\n");
			printf("- Digite 0: Para voltar ao menu principal.\n\n");
			scanf("%d",&a);setbuf(stdin,NULL);

			escolha = a;
			return escolha;			
		}

		/*Função 'MenuAluno'.*/

		int MenuAluno()
		{
			int escolha, a;

			printf("\n- Digite 1: Para inserir aluno.\n");
			printf("- Digite 2: Para excluir aluno.\n");		
			printf("- Digite 3: Para atualizar aluno.\n");		
			printf("- Digite 0: Para voltar ao menu principal.\n\n");
			scanf("%d",&a);setbuf(stdin,NULL);

			escolha = a;
			return escolha;	
		}

		/*Função 'MenuProfessor'.*/

		int MenuProfessor()
		{
			int escolha, a;

			printf("\n- Digite 1: Para inserir professor.\n");
			printf("\n- Digite 2: Para excluir professor.\n");
			printf("\n- Digite 3: Para atualizar professor.\n");
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
					cadastro disc = InserirDisciplina();
				}
				else
				{
					if (op2 == 2)
					{
						/*função exlcuir disciplina*/
					}
					else
					{
						if (op2 == 3)
						{
							/* função atualizar disciplina */
						}
						else
						{
							if (op2 != 0 && op2 >3)
							{
								printf("Opção inválida!\n");
								op2 = MenuDisciplina();
							}
						}
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
						dados alun = InserirAluno();
					}
					else
					{
						if (op2 == 2)
						{
							/* função escluir aluno */
						}
						else
						{
							if (op2 == 3)
							{
								/* função atualizar aluno */
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
							dados prof = InserirProfessor();
						}
						else
						{
							if (op2 == 2)
							{
								/*função excluir professor*/
							}
							else
							{
								if (op2 == 3)
								{
									/* função atualizar professor */
								}
								else
								{
									if (op2 != 0 && op2 >3)
									{
										printf("Opção inválida!\n");
										op2 = MenuProfessor();
									}
								}
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

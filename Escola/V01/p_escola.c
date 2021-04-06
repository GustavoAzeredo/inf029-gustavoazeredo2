#include <stdio.h>
#include <string.h>

/*Definição das struct de cadastro dos alunos e professores.*/

typedef struct
{
	char matricula[10];
	char nome[40];
	char sexo;
	char cpf[15];
	int dia;
	int mes;
	int ano;
}dados;

dados aluno[5];
dados professor[5];

/*Definição da struct de cadastro das disciplinas.*/

typedef struct
{
	char nome[15];
	char codigo[10];
	char professor[40];
	char semestre[5];
}cadastro;

cadastro disciplinas[5];

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

		/*Função de 'InserirDisciplina'.*/

		cadastro InserirDisciplina()
		{
			int op3, i=0, cont=1;
			cadastro dis[5];

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
			
			return dis[5];
		}

		/*Função ExcluirDisciplina*/
		/*Função AtualizarDisciplina */



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

		/*Função de 'InserirAlunos'.*/

		void InserirAluno()
		{
			int op3, op1, i=0, cont=1;
			dados aluno[5];

			do
			{
				printf("Digite a matrícula do aluno: \n");
				gets(aluno[i].matricula);
				printf("Digite o nome do aluno: \n");
				gets(aluno[i].nome);
				printf("Digite o cpf do aluno: \n");
				gets(aluno[i].cpf);
				printf("Digite o sexo do aluno: \n");
				scanf("%c",&aluno[i].sexo);setbuf(stdin,NULL);
				printf("Digite a data de nascimento do aluno: \n");
				scanf("%d%d%d",&aluno[i].dia,&aluno[i].mes,&aluno[i].ano);setbuf(stdin,NULL);
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
				}
			} while (i<cont);

			printf("Matricula\tNome\tCPF\n");
			for (i = 0; i < cont; ++i)
			{
				printf("%s\t%s\t%s\n",aluno[i].matricula,aluno[i].nome,aluno[i].cpf);
			}

			op1 = loop();

			
		}

		/*Função 'ExcuirAluno'.*/

		dados ExcluirAluno()
		{
			int i=0;
			char exc[10], a[10]="Excluído";
			

			
			do
			{
				if (strcmp(exc,aluno[i].matricula))
				{
					i++;
				}
				else
				{
					strcpy(aluno[i].matricula,a);
					i++;
				}
			} while (i<5);

			printf("Matricula\tNome\tCPF\n");

			for (int j = 0; j < 5; ++j)
			{
				printf("%s\t%s\t%s\n",aluno[j].matricula,aluno[j].nome,aluno[j].cpf);
			}
			return aluno[5];
		}

		/*Função AtualizarAluno*/


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

		/*Função de InserirProfessor'.*/

		dados InserirProfessor()
		{
			int op3, op1, i=0, cont=1;
			dados prof[5];

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
					op1 = loop();
				}
			} while (i<cont);

			return prof[5];
		}

		/*Função ExcluirProfessor*/
		/*Função AtualizarProfessor*/

		

		
	/*Função Pirncipal*/

	int loop()
	{
		int op1, op2;
		dados aluno[5];
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
							InserirAluno();
						}
						else
						{
							if (op2 == 2)
							{
								dados aluno = ExcluirAluno();
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
		return op1;
	}	
		
/*Função main*/

int main(int argc, char const *argv[])
{
	int op1, op2;

	op1=loop();

	return 0;
}
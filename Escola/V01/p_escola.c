#include <stdio.h>
#include <string.h>

/*Definição das struct de cadastro dos alunos e professores.*/

typedef struct
{
	int matricula;
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

		void InserirDisciplina()
		{
			int op3, op1, i=0, cont=1;
			cadastro disciplina[5];

			do
			{
				printf("Digite o nome da disciplina: \n");
				gets(disciplina[i].nome);setbuf(stdin,NULL);
				printf("Digite o código da disciplina: \n");
				gets(disciplina[i].codigo);setbuf(stdin,NULL);
				printf("Digite o nome do professor: \n");
				gets(disciplina[i].professor);setbuf(stdin,NULL);
				printf("Digite o semestre da disciplina: \n\n");
				gets(disciplina[i].semestre);setbuf(stdin,NULL);
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

			printf("Código\tNome\tSemestre\n");
			for (i = 0; i < cont; ++i)
			{
				printf("%s\t%s\t%s\n",disciplina[i].codigo,disciplina[i].nome,disciplina[i].semestre);
			}

			op1 = loop();
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
			int op3, op1, i=0, cont=1, mataluno = 100;
						
			do
			{
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
				aluno[i].matricula = mataluno + 1;
				
				if (op3==1)
				{
					i++;
					cont++;
					mataluno++;
				}
				else
				{
					i++;
					cont=cont;
				}
			} while (i!=cont && cont<=5);

			printf("\nAlunos Cadastrados:\n\n");
			printf("Matricula\tNome\t\tCPF\n\n");
			for (int j = 0; j < cont; ++j)
			{
				printf("%d\t\t%s\t\t%s\n",aluno[j].matricula,aluno[j].nome,aluno[j].cpf);
			}

			op1 = loop();
			return ;
		}

		/*Função 'ExcuirAluno'.*/

		void ExcluirAluno()
		{
			int excluir, cont=5, op1;

			printf("\nAlunos Cadastrados:\n\n");
			printf("Matricula\tNome\t\tCPF\n\n");
			for (int i = 0; i < cont; ++i)
			{
				printf("%d\t\t%s\t\t%s\n",aluno[i].matricula,aluno[i].nome,aluno[i].cpf);
			}

			printf("\nDigite a matrícula que deseja excluir: \n");
			scanf("%d",&excluir);setbuf(stdin,NULL);

			int j=0;
			do
			{
				if (excluir==aluno[j].matricula)
				{
					aluno[j].matricula = -1;
				}
				else
				{
					j++;
				}
			} while (j<=cont);

			int k=0;
			do
			{
				if (aluno[k].matricula==-1)
				{
					do
					{
						aluno[k]=aluno[k+1];
						k++;

					} while (k<cont-1);
				}
				else
				{
					k++;
				}
			} while (k<cont);
			
			printf("\nAlunos Cadastrados:\n\n");
			printf("Matricula\tNome\t\tCPF\n\n");
			for (int l = 0; l < cont; ++l)
			{
				printf("%d\t\t%s\t\t%s\n",aluno[l].matricula,aluno[l].nome,aluno[l].cpf);
			}
			
			op1 = loop();
			
			return ;
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

		void InserirProfessor()
		{
			int op3, op1, i=0, cont=1, matprofessor = 1000;
			
			do
			{
				
				printf("Digite o nome do professor: \n");
				gets(professor[i].nome);setbuf(stdin,NULL);
				printf("Digite o sexo do professor: \n");
				gets(professor[i].sexo);setbuf(stdin,NULL);
				printf("Digite o cpf do professor: \n");
				gets(professor[i].cpf);setbuf(stdin,NULL);
				printf("Digite a data de nascimento do professor: \n");
				scanf("%d%d%d",&professor[i].dia,&professor[i].mes,&professor[i].ano);setbuf(stdin,NULL);
				printf("\n\nDigite 1: Para continuar.\n");
				printf("Digite 0: Para encerrar.\n\n");
				scanf("%d",&op3);setbuf(stdin,NULL);
				professor[i].matricula = matprofessor + 1;
				
				if (op3==1)
				{
					i++;
					cont++;
					matprofessor++;
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
				printf("%d\t%s\t%s\n",professor[i].matricula,professor[i].nome,professor[i].cpf);
			}

			op1 = loop();
			
		}

		/*Função ExcluirProfessor*/



		/*Função AtualizarProfessor*/

		

	/*Função Pirncipal, "troca" de munu.*/

	int loop()
	{
		int op1, op2, cont;
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
						InserirDisciplina();
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
								ExcluirAluno();
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
								InserirProfessor();
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
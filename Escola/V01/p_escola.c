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
	int codigo;
	char professor[40];
	char semestre[5];
}cadastro;

cadastro disciplina[5];

	/*Função 'MenuPrincipal', pergunta para qual submenu o usuário quer ir.*/

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

	/*Função 'MenuDisciplina', pergunta qual a ação o usuário quer fazer com as disciplinas.*/

	int MenuDisciplina()
	{
		int escolha, b;

		printf("\n- Digite 1: Para inserir disciplina.\n");
		printf("\n- Digite 2: Para excluir disciplina.\n");
		printf("\n- Digite 3: Para atualizar disciplina.\n");
		printf("- Digite 0: Para voltar ao menu principal.\n\n");
		scanf("%d",&b);setbuf(stdin,NULL);

		escolha = b;
		return escolha;			
	}

		/*Função de 'InserirDisciplina', cadastra uma ou mais disciplinas.*/

		void InserirDisciplina()
		{
			int op3, op1, i=0, cont=1, codigo = 0;
			
			do
			{
				printf("Digite o nome da disciplina: \n");
				gets(disciplina[i].nome);setbuf(stdin,NULL);
				printf("Digite o nome do professor: \n");
				gets(disciplina[i].professor);setbuf(stdin,NULL);
				printf("Digite o semestre da disciplina: \n\n");
				gets(disciplina[i].semestre);setbuf(stdin,NULL);
				printf("\n\nDigite 1: Para continuar.\n");
				printf("Digite 0: Para encerrar.\n\n");
				scanf("%d",&op3);setbuf(stdin,NULL);
				disciplina[i].codigo = codigo + 1;

				if (op3==1)
				{
					i++;
					cont++;
					codigo++;
				}
				else
				{
					i++;
					cont=cont;
				}
			} while (i!=cont && i<=5);

			/*Listagem de disciplina.*/

			printf("Código\tNome\tProfessor\tSemestre\n");
			for (i = 0; i < cont; ++i)
			{
				printf("%d\t%s\t%s\t%s\n",disciplina[i].codigo,disciplina[i].nome,disciplina[i].professor,disciplina[i].semestre);
			}

			op1 = loop();
		}

		/*Função 'ExcluirDisciplina', exclui uma disciplina.*/

		void ExcluirDisciplina()
		{
			int excluir, cont=5, op1;

			printf("\nDisciplinas Cadastrados:\n\n");
			printf("Código\tNome\t\tSemestre\n\n");
			for (int i = 0; i < cont; ++i)
			{
				printf("%d\t\t%s\t\t%s\n",disciplina[i].codigo,disciplina[i].nome,disciplina[i].semestre);
			}

			printf("\nDigite o código que deseja excluir: \n");
			scanf("%d",&excluir);setbuf(stdin,NULL);

			int j=0;

			do
			{
				if (excluir==disciplina[j].codigo)
				{
					disciplina[j].codigo = -1;
				}
				else
				{
					j++;
				}
			} while (j<=cont);

			int k=0;

			do
			{
				if (disciplina[k].codigo==-1)
				{
					do
					{
						disciplina[k]=disciplina[k+1];
						k++;

					} while (k<cont-1);
				}
				else
				{
					k++;
				}
			} while (k<cont);
			
			printf("\nDisciplinas Cadastrados:\n\n");
			printf("Código\tNome\t\tSemestre\n\n");

			for (int l = 0; l < cont; ++l)
			{
				printf("%d\t\t%s\t\t%s\n",disciplina[l].codigo,disciplina[l].nome,disciplina[l].semestre);
			}
			
			op1 = loop();
			
			return ;
		}

		/*Função 'AtualizarDisciplina'.*/



	/*Função 'MenuAluno', pergunta ao usuário qual a ação fazer com aluno.*/

	int MenuAluno()
	{
		int escolha, c;

		printf("\n- Digite 1: Para inserir aluno.\n");
		printf("- Digite 2: Para excluir aluno.\n");		
		printf("- Digite 3: Para atualizar aluno.\n");		
		printf("- Digite 0: Para voltar ao menu principal.\n\n");
		scanf("%d",&c);setbuf(stdin,NULL);

		escolha = c;
		return escolha;
	}

		/*Função de 'InserirAlunos', cadastra um ou mais alunos.*/

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

			/*Listagem de Alunos*/

			printf("\nAlunos Cadastrados:\n\n");
			printf("Matricula\tNome\t\tCPF\tSexo\tData de Nascimento\n\n");

			for (int j = 0; j < cont; ++j)
			{
				printf("%d\t\t%s\t\t%s\t%c\t%d/%d/%d\n",aluno[j].matricula,aluno[j].nome,aluno[j].cpf,aluno[j].sexo,aluno[j].dia,aluno[j].mes,aluno[j].ano);
			}

			op1 = loop();
			return ;
		}

		/*Função 'ExcuirAluno', exclui um aluno cadastrado.*/

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

		/*Função 'AtualizarAluno'.*/



	/*Função 'MenuProfessor', pergunta ao usuário, qual ação realizar com professor.*/	

	int MenuProfessor()
	{
		int escolha, d;

		printf("\n- Digite 1: Para inserir professor.\n");
		printf("- Digite 2: Para excluir professor.\n");		
		printf("- Digite 3: Para atualizar professor.\n");		
		printf("- Digite 0: Para voltar ao menu principal.\n\n");
		scanf("%d",&d);setbuf(stdin,NULL);

		escolha = d;
		return escolha;
	}

		/*Função 'InserirProfessor', cadastra um ou mais professor.*/

		void InserirProfessor()
		{
			int op3, op1, i=0, cont=1, matprofessor = 1000;
			
			do
			{
				
				printf("Digite o nome do professor: \n");
				gets(professor[i].nome);
				printf("Digite o cpf do professor: \n");
				gets(professor[i].cpf);
				printf("Digite o sexo do professor: \n");
				scanf("%c",&professor[i].sexo);setbuf(stdin,NULL);
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
			} while (i!=cont && cont<=5);
			
			/*Listagem de Professores.*/

			printf("\nProfessores Cadastrados:\n\n");
			printf("Matricula\tNome\t\tCPF\tSexo\tData de Nascimento\n\n");
			
			for (int j = 0; j < cont; ++j)
			{
				printf("%d\t\t%s\t\t%s\t%c\t%d/%d/%d\n",professor[j].matricula,professor[j].nome,professor[j].cpf,professor[j].sexo,professor[j].dia,professor[j].mes,professor[j].ano);
			}

			op1 = loop();
			return ;
		}

		/*Função 'ExcuirProfessor', exclui um professor.*/

		void ExcluirProfessor()
		{

			int excluir, cont=5, op1;

			printf("\nProfessores Cadastrados:\n\n");
			printf("Matricula\tNome\t\tCPF\n\n");

			for (int i = 0; i < cont; ++i)
			{
				printf("%d\t\t%s\t\t%s\n",professor[i].matricula,professor[i].nome,professor[i].cpf);
			}

			printf("\nDigite a matrícula que deseja excluir: \n");
			scanf("%d",&excluir);setbuf(stdin,NULL);

			int j=0;

			do
			{
				if (excluir==professor[j].matricula)
				{
					professor[j].matricula = -1;
				}
				else
				{
					j++;
				}
			} while (j<=cont);

			int k=0;

			do
			{
				if (professor[k].matricula==-1)
				{
					do
					{
						professor[k]=professor[k+1];
						k++;
					} while (k<cont-1);
				}
				else
				{
					k++;
				}
			} while (k<cont);
			
			printf("\nProfessores Cadastrados:\n\n");
			printf("Matricula\tNome\t\tCPF\n\n");

			for (int l = 0; l < cont; ++l)
			{
				printf("%d\t\t%s\t\t%s\n",professor[l].matricula,professor[l].nome,professor[l].cpf);
			}
			
			op1 = loop();
			return ;
		}

		/*Função 'AtualizarProfessor'.*/

		

	/*Função 'loop', "troca" de menu.*/

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
							ExcluirDisciplina();
						}
						else
						{
							if (op2 == 3)
							{
								/* função atualizar disciplina.*/
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
									/* função atualizar aluno.*/
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
									ExcluirProfessor();
								}
								else
								{
									if (op2 == 3)
									{
										/* função atualizar professor.*/
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
		
/*Função main.*/

int main(int argc, char const *argv[])
{
	int op1, op2;

	op1=loop();

	return 0;
}
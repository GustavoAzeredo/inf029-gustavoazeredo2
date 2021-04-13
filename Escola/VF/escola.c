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
	dados professor;
	dados aluno[5];
	char semestre[5];
}cadastro;

cadastro disciplina[5];

	/*Função 'MenuPrincipal', pergunta para qual submenu o usuário quer ir.*/

	int MenuPrincipal()
	{
		int escolha, a;

		printf("\nBem vindo ao sistema eletrônico!\n\n");
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
		printf("- Digite 2: Para excluir disciplina.\n");
		printf("- Digite 3: Para matricular aluno.\n");
		printf("- Digite 4: Para listar disciplina.\n");
		printf("- Digite 5: Para atualizar disciplina.\n");
		printf("- Digite 0: Para voltar ao menu principal.\n\n");
		scanf("%d",&b);setbuf(stdin,NULL);

		escolha = b;
		return escolha;			
	}

		/*Função de 'InserirDisciplina', cadastra uma ou mais disciplinas.*/

		void InserirDisciplina()
		{
			int op3, op1, i=0, cont=5, aux=1, codigo = 0;
			int inserir, tn;
			dados docente[5];
			do
			{
				printf("\nDigite o nome da disciplina: ");
				fgets(disciplina[i].nome,15,stdin);

				tn = strlen(disciplina[i].nome);
				if (disciplina[i].nome[tn-1]=='\n')
				{
					disciplina[i].nome[tn-1]='\0';
				}

				printf("Digite o semestre da disciplina: ");
				fgets(disciplina[i].semestre,5,stdin);

				tn = strlen(disciplina[i].semestre);
				if (disciplina[i].semestre[tn-1]=='\n')
				{
					disciplina[i].semestre[tn-1]='\0';
				}

				printf("\n\nProfessores Cadastrados:\n\n");
				printf("Matricula\tNome\n\n");
				
				for (int j = 0; j < cont; ++j)
				{
					printf("%d\t\t%s\n",professor[j].matricula,professor[j].nome);
				}

				printf("\nDigite a matricula do professor que irá lecionar essa disciplina: ");
				scanf("%d",&inserir);setbuf(stdin,NULL);
				for (int k = 0; k < cont; ++k)
				{
					if (inserir==professor[k].matricula)
					{
						docente[i]=professor[k];
					}
				}
				
				printf("\n\nDigite 1: Para continuar.\n");
				printf("Digite 0: Para encerrar.\n\n");
				scanf("%d",&op3);setbuf(stdin,NULL);

				disciplina[i].codigo = codigo + 1;

				if (op3==1)
				{
					i++;
					aux++;
					codigo++;
				}
				else
				{
					i++;
					aux=aux;
				}
			} while (i!=aux && i<=5);

			/*Listagem de disciplina.*/

			printf("\nDisciplinas cadastradas: \n");
			printf("\nCódigo\tNome\t\tSemestre\tProfessor(matricula/nome)\n\n");
			for (int l = 0; l < aux; ++l)
			{
				printf("%d\t%s\t%s\t\t%d %s\n",disciplina[l].codigo,disciplina[l].nome,disciplina[l].semestre,docente[l].matricula,docente[l].nome);
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

		/*Função MatricularAluno', que matricula um aluno em uma ou mais disciplina.*/

		void MatricularAluno()
		{
			int matricular, inserir;
			int cont=5;
			cadastro discente;

			printf("\nAlunos Cadastrados:\n\n");
			printf("Matricula\tNome\t\tCPF\n\n");

				for (int i = 0; i < cont; ++i)
				{
					printf("%d\t\t%s\t\t%s\n",aluno[i].matricula,aluno[i].nome,aluno[i].cpf);
				}

			printf("\nDigite a matrícula que deseja matricular: \n");
			scanf("%d",&matricular);setbuf(stdin,NULL);

			printf("\nDisciplinas Cadastrados:\n\n");
			printf("Código\tNome\t\tSemestre\n\n");

				for (i = 0; i < cont; ++i)
				{
					printf("%d\t\t%s\t\t%s\n",disciplina[i].codigo,disciplina[i].nome,disciplina[i].semestre);
				}

			printf("\nDigite o código da disciplina na qual o aluno será matriculado: \n");
			scanf("%d",&inserir);setbuf(stdin,NULL);

			for (i = 0; i < cont; ++i)
			{
				for (int j = 0; j < cont; ++j)
				{
					for (int k = 0; k < cont; ++k)
					{
						if (matricular==aluno[j].matricula && inserir==disciplina[k].codigo)
						{
							discente[i]=aluno[j];
						}
					}
				}
			}
		}

		/*Função 'ListarDisciplina', que lista as disciplinas com os alunos matriculados.*/

		void ListarDisciplina();
		{
			printf("\nDisciplinas cadastradas: \n");
			printf("\nCódigo\tNome\t\tSemestre\tProfessor(matricula/nome)\n\n");
			for (int l = 0; l < aux; ++l)
			{
				printf("%d\t%s\t%s\t\t%d %s\n",disciplina[l].codigo,disciplina[l].nome,disciplina[l].semestre,docente[l].matricula,docente[l].nome);
			}
			printf("\nAlunos matriculados:\n");
			printf("Matricula\tNome\t\tCPF\n\n");

			for (int j = 0; j < cont; ++j)
			{
				printf("%d\t\t%s\t\t%s\t%c\t%d/%d/%d\n",discente[j].matricula,discente[j].nome,discente[j].cpf);
			}
		}

		void AtualizarDisciplina()
		{
			
		}

	/*Função 'MenuAluno', pergunta ao usuário qual a ação fazer com aluno.*/

	int MenuAluno()
	{
		int escolha, c;

		printf("\n- Digite 1: Para inserir aluno.\n");
		printf("- Digite 2: Para excluir aluno.\n");		
		printf("- Digite 3: Para listar aluno.\n");
		printf("- Digite 4: Para atualizar aluno.\n");		
		printf("- Digite 0: Para voltar ao menu principal.\n\n");
		scanf("%d",&c);setbuf(stdin,NULL);

		escolha = c;
		return escolha;
	}

		/*Função de 'InserirAlunos', cadastra um ou mais alunos.*/

		void InserirAluno()
		{
			int op3, op1, i=0, cont=1, mataluno = 100, tn;
						
			do
			{
				printf("\nDigite o nome do aluno: ");
				fgets(aluno[i].nome,40,stdin);setbuf(stdin,NULL);

					tn = strlen(aluno[i].nome);
					if (aluno[i].nome[tn-1]=='\n')
					{
						aluno[i].nome[tn-1]='\0';
					}

				printf("Digite o cpf do aluno: ");
				fgets(aluno[i].cpf,20,stdin);setbuf(stdin,NULL);

					tn = strlen(aluno[i].cpf);
					if (aluno[i].cpf[tn-1]=='\n')
					{
						aluno[i].cpf[tn-1]='\0';
					}

				printf("Digite o sexo do aluno: ");
				scanf("%c",&aluno[i].sexo);setbuf(stdin,NULL);
				printf("Digite a data de nascimento do aluno: ");
				scanf("%d%d%d",&aluno[i].dia,&aluno[i].mes,&aluno[i].ano);setbuf(stdin,NULL);
				printf("\n\nDigite 1: Para continuar.\n");
				printf("Digite 0: Para encerrar.\n\n");
				scanf("\n%d",&op3);setbuf(stdin,NULL);

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
			printf("Matricula\tNome\t\tCPF\t\tSexo\tData de Nascimento\n\n");

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
			printf("Matricula\tNome\t\tCPF\n");

				for (int l = 0; l < cont; ++l)
				{
					printf("%d\t\t%s\t\t%s\n",aluno[l].matricula,aluno[l].nome,aluno[l].cpf);
				}
			
			op1 = loop();
			return ;
		}

		/*Função 'ListarAluno', que lista os alunos por critérios específicos.*/

		void ListarAluno()
		{
			int op1, op4;
			dados lista[5];

			printf("\nDigite 1: Para listar alunos por ordem alfabética.\n");
			printf("Digite 2: Para listar alunos por data de nascimento.\n");
			printf("Digite 3: Para listar alunos por sexo.\n");
			printf("Digite 0: Para voltar ao menu principal.\n");
			scanf("%d\n",&op4);

			switch(op4)
			{
				case 1:
				{

				}
				break;
				case 2:
				{
					int v[5], t[5];
					int aux=0, aux1=-1, aux2;

					for (int i = 0; i < 5; ++i)
					{
						t[i]=-1;
					}
						for (int j = 0; j < 5; ++j)
						{
							v[j]=(((((aluno[j].ano)*100)+aluno[j].mes)*100)+aluno[j].dia);
						}
							for (int k = 0; k < 5; ++k)
							{
								aux=0;
								for (int l = 0; l < 5; ++l)
								{
									if (v[k]>=v[l])
									{
										aux++;
									}
									else
									{
										aux=aux;
									}
								}
								aux1++;
								aux2=aux-1;
								
									for (int m = 0; m < 5; ++m)
									{
										if (aux2!=t[m])
										{
											aux2=aux2;
										}
										else
										{
											aux2--;
										}
									}
									t[aux1]=aux2;
									lista[aux2]=aluno[k];
							}
							for (int n = 0; n < 5; ++n)
							{
								if (lista[n].matricula<=100)
								{
									printf("\t");
								}
								else
								{
									printf("%d\t%s\t%d/%d/%d\n",lista[n].matricula,lista[n].nome,lista[n].dia,lista[n].mes,lista[n].ano);
								}
								
							}
				}
				break;
				case 3:
				{

				}
				break;
				case 0:
				{
					op1 = loop();
				}
				break;
				default:
				{
					printf("Opção inválida!\n");
					ListarAluno();
				}
			}
		}

		/*Função 'AtualizarAluno', que serve para modificar os dados cadastrados de forma interativa.*/

		void AtualizarAluno()
		{
			int atualizar, cont=5, op1, tn;

			printf("\nAlunos Cadastrados:\n\n");
			printf("Matricula\tNome\t\tCPF\t\tSexo\tData de Nascimento\n\n");

				for (int i = 0; i < cont; ++i)
				{
					printf("%d\t\t%s\t\t%s\t%c\t%d/%d/%d\n",aluno[i].matricula,aluno[i].nome,aluno[i].cpf,aluno[i].sexo,aluno[i].dia,aluno[i].mes,aluno[i].ano);
				}

			printf("\nDigite a matrícula que deseja atualizar: \n");
			scanf("%d",&atualizar);setbuf(stdin,NULL);

			for (int j = 0; j < cont; ++j)
			{
				if (aluno[j].matricula==atualizar)
				{
					printf("\nDigite o nome do aluno: ");
					fgets(aluno[j].nome,40,stdin);setbuf(stdin,NULL);

					tn = strlen(aluno[j].nome);
					if (aluno[j].nome[tn-1]=='\n')
					{
						aluno[j].nome[tn-1]='\0';
					}

					printf("Digite o cpf do aluno: ");
					fgets(aluno[j].cpf,20,stdin);setbuf(stdin,NULL);

						tn = strlen(aluno[j].cpf);
					if (aluno[j].cpf[tn-1]=='\n')
					{
						aluno[j].cpf[tn-1]='\0';
					}

					printf("Digite o sexo do aluno: ");
					scanf("%c",&aluno[j].sexo);setbuf(stdin,NULL);
					printf("Digite a data de nascimento do aluno: ");
					scanf("%d%d%d",&aluno[j].dia,&aluno[j].mes,&aluno[j].ano);setbuf(stdin,NULL);
				}
			}

			printf("\nCadastro Atualizado:\n\n");
			printf("Matricula\tNome\t\tCPF\t\tSexo\tData de Nascimento\n\n");

				for (int k = 0; k < cont; ++k)
				{
					printf("%d\t\t%s\t\t%s\t%c\t%d/%d/%d\n",aluno[k].matricula,aluno[k].nome,aluno[k].cpf,aluno[k].sexo,aluno[k].dia,aluno[k].mes,aluno[k].ano);
				}
		}

	/*Função 'MenuProfessor', pergunta ao usuário, qual ação realizar com professor.*/	

	int MenuProfessor()
	{
		int escolha, d;

		printf("\n- Digite 1: Para inserir professor.\n");
		printf("- Digite 2: Para excluir professor.\n");		
		printf("- Digite 3: Para listar professor.\n");
		printf("- Digite 4: Para atualizar professor.\n");		
		printf("- Digite 0: Para voltar ao menu principal.\n\n");
		scanf("%d",&d);setbuf(stdin,NULL);

		escolha = d;
		return escolha;
	}

		/*Função 'InserirProfessor', cadastra um ou mais professor.*/

		void InserirProfessor()
		{
			int op3, op1, i=0, cont=1, matprofessor = 1000, tn;
			
			do
			{				
				printf("\nDigite o nome do professor: ");
				fgets(professor[i].nome,40,stdin);

					tn = strlen(professor[i].nome);
					if (professor[i].nome[tn-1]=='\n')
					{
						professor[i].nome[tn-1]='\0';
					}

				printf("Digite o cpf do professor: ");
				fgets(professor[i].cpf,15, stdin);

					tn = strlen(professor[i].cpf);
					if (professor[i].cpf[tn-1]=='\n')
					{
						professor[i].cpf[tn-1]='\0';
					}

				printf("Digite o sexo do professor: ");
				scanf("%c",&professor[i].sexo);setbuf(stdin,NULL);
				printf("Digite a data de nascimento do professor: ");
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
			printf("Matricula\tNome\t\tCPF\t\tSexo\tData de Nascimento\n\n");
			
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

		/*Função 'ListarProfessor', que lista os prfessores por critérios específicos.*/

		void ListarProfessor()
		{
			int op1, op4;
			dados lista[5];

			printf("\nDigite 1: Para listar professores por ordem alfabetica.\n");
			printf("Digite 2: Para listar professores por data de nascimento.\n");
			printf("Digite 3: Para listar professores por sexo.\n");
			printf("Digite 0: Para voltar ao menu principal.\n");
			scanf("%d\n",&op4);

			switch(op4)
			{
				case 1:
				{

				}
				break;
				case 2:
				{
					int v[5], t[5];
					int aux=0, aux1=-1, aux2;

					for (int i = 0; i < 5; ++i)
					{
						t[i]=-1;
					}
						for (int j = 0; j < 5; ++j)
						{
							v[j]=(((((professor[j].ano)*100)+professor[j].mes)*100)+professor[j].dia);
						}
							for (int k = 0; k < 5; ++k)
							{
								aux=0;
								for (int l = 0; l < 5; ++l)
								{
									if (v[k]>=v[l])
									{
										aux++;
									}
									else
									{
										aux=aux;
									}
								}
								aux1++;
								aux2=aux-1;
								
									for (int m = 0; m < 5; ++m)
									{
										if (aux2!=t[m])
										{
											aux2=aux2;
										}
										else
										{
											aux2--;
										}
									}
									t[aux1]=aux2;
									lista[aux2]=professor[k];
							}
							for (int n = 0; n < 5; ++n)
							{
								printf("%d\t%s\t%d/%d/%d\n",lista[n].matricula,lista[n].nome,lista[n].dia,lista[n].mes,lista[n].ano);
							}
				}
				break;
				case 3:
				{

				}
				break;
				case 0:
				{
					op1 = loop();
				}
				break;
				default:
				{
					printf("Opção inválida!\n");
					ListarProfessor();
				}
			}
		}

		/*Função 'AtualizarProfessor', que serve para modificar os dados cadastrados de forma interativa.*/

		void AtualizarProfessor()
		{
			int atualizar, cont=5, op1, tn;

			printf("\nProfessores Cadastrados:\n\n");
			printf("Matricula\tNome\t\tCPF\t\tSexo\tData de Nascimento\n\n");

				for (int i = 0; i < cont; ++i)
				{
					printf("%d\t\t%s\t\t%s\t%c\t%d/%d/%d\n",professor[i].matricula,professor[i].nome,professor[i].cpf,professor[i].sexo,professor[i].dia,professor[i].mes,professor[i].ano);
				}

			printf("\nDigite a matrícula que deseja atualizar: \n");
			scanf("%d",&atualizar);setbuf(stdin,NULL);

			for (int j = 0; j < cont; ++j)
			{
				if (professor[j].matricula==atualizar)
				{
					printf("\nDigite o nome do professor: ");
					fgets(professor[j].nome,40,stdin);setbuf(stdin,NULL);

					tn = strlen(professor[j].nome);
					if (professor[j].nome[tn-1]=='\n')
					{
						professor[j].nome[tn-1]='\0';
					}

					printf("Digite o cpf do professor: ");
					fgets(professor[j].cpf,20,stdin);setbuf(stdin,NULL);

						tn = strlen(professor[j].cpf);
					if (professor[j].cpf[tn-1]=='\n')
					{
						professor[j].cpf[tn-1]='\0';
					}

					printf("Digite o sexo do professor: ");
					scanf("%c",&professor[j].sexo);setbuf(stdin,NULL);
					printf("Digite a data de nascimento do professor: ");
					scanf("%d%d%d",&professor[j].dia,&professor[j].mes,&professor[j].ano);setbuf(stdin,NULL);
				}
			}

			printf("\nCadastro Atualizado:\n\n");
			printf("Matricula\tNome\t\tCPF\t\tSexo\tData de Nascimento\n\n");

				for (int k = 0; k < cont; ++k)
				{
					printf("%d\t\t%s\t\t%s\t%c\t%d/%d/%d\n",professor[k].matricula,professor[k].nome,professor[k].cpf,professor[k].sexo,professor[k].dia,professor[k].mes,professor[k].ano);
				}
		}

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
								MatricularAluno();
							}
							else
							{
								if (op2 == 4)
								{
									ListarDisciplina();
								}
								else
								{
									if (op2 == 5)
									{
										AtualizarDisciplina();
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
									ListarAluno();
								}
								else
								{
									if (op2 == 4)
									{
										AtualizarAluno();
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
										ListarProfessor();
									}
									else
									{
										if (op2==4)
										{
											AtualizarProfessor();
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
	int op1, op2, op5, mesatual;

	op1=loop();

	printf("\nQuer saber os aniversariantes do mês? \n\n");
	printf("Digite 1: Para sim.\n");
	printf("Digite 0: Para não.\n\n");
	scanf("%d",&op5);

	if (op5==0)
	{
		printf("\nSair!\n");
	}
	else
	{
		printf("Digite o mês atual: \n");
		scanf("%d\n",&mesatual);

		for (int i = 0; i < 5; ++i)
		{
			if (mesatual==aluno[i].mes)
			{
				printf("%d\t%s\t%d/%d/%d\n",aluno[i].matricula,aluno[i].nome,aluno[i].dia,aluno[i].mes,aluno[i].ano);
			}	
			if (mesatual==professor[i].mes)
			{
				printf("%d\t%s\t%d/%d/%d\n",professor[i].matricula,professor[i].nome,professor[i].dia,professor[i].mes,professor[i].ano);
			}
		}
	}
		
	return 0;
}
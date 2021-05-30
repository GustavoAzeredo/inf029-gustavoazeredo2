#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int ***vetorPrincipal;

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)//OK
{
	int retorno = 0;
	int n = tamanho + 1;

	if (posicao<1||posicao>10)
	{
		retorno = POSICAO_INVALIDA;
	}
	else
	{
		if (vetorPrincipal[posicao]!=NULL)
		{
			retorno = JA_TEM_ESTRUTURA_AUXILIAR;
		}
		else
		{
			if (tamanho<1)
			{
				retorno = TAMANHO_INVALIDO;
			}
			else
			{
				vetorPrincipal[posicao] = malloc(n*sizeof(int *));
				for (int i = 0; i < n; ++i)
				{
					vetorPrincipal[posicao][i] = NULL;
				}
				if (vetorPrincipal[posicao]==NULL)
				{
					retorno = SEM_ESPACO_DE_MEMORIA;
				}
				else
				{
					vetorPrincipal[posicao][0] = malloc(sizeof(int));
					*vetorPrincipal[posicao][0] = tamanho;
					retorno = SUCESSO;
				}
			}
		}
	}

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Retorno (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)//OK
{
	int retorno = 0;
	
	if (posicao<1||posicao>10)
	{
		retorno = POSICAO_INVALIDA;
	}
	else
	{
		if (vetorPrincipal[posicao]==NULL)
		{
			retorno = SEM_ESTRUTURA_AUXILIAR;
		}
		else
		{
			for (int i = 1; i <= *vetorPrincipal[posicao][0]; ++i)
			{
				if (vetorPrincipal[posicao][i]==NULL)
				{
					vetorPrincipal[posicao][i] = malloc(sizeof(int));
					*vetorPrincipal[posicao][i] = valor;
					retorno = SUCESSO;
                    break;
				}
                else
                {
                    retorno = SEM_ESPACO;
                }
			}
		}
	}
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)//OK
{
    int retorno = 0;

    if (posicao<1||posicao>10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
    {
        if (vetorPrincipal[posicao]==NULL)
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
        else
        {

            for (int i = *vetorPrincipal[posicao][0]; i >= 1; --i)
            {
                if (vetorPrincipal[posicao][i]!=NULL)
                {
                    vetorPrincipal[posicao][i] = NULL;
                    retorno = SUCESSO;
                    break;
                }
                else
                {
                    retorno = ESTRUTURA_AUXILIAR_VAZIA;
                }
            }
        }
    }
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)//OK
{
    int retorno = 0, vazio = 0, igual = 0;
    
    if (posicao<1||posicao>10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
    {
        if (vetorPrincipal[posicao]==NULL)
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
        else
        {
            for (int i = 1; i <= *vetorPrincipal[posicao][0]; ++i)
            {
                if (vetorPrincipal[posicao][i]!=NULL)
                {
                    vazio++;
                    if (*vetorPrincipal[posicao][i]==valor)
                    {
                    	igual++;
                        for (int j = i; j < *vetorPrincipal[posicao][0]; ++j)//inicio do shift
                        {
                        	if (vetorPrincipal[posicao][j+1]!=NULL)
                        	{
                        		*vetorPrincipal[posicao][j] = *vetorPrincipal[posicao][j+1];
                        	}
                        	else
                        	{
                        		vetorPrincipal[posicao][j] = NULL;
                        	}
                        	
                        }//final do shift
                        retorno = SUCESSO;
                        break;
                    }
                    else
                    {
                    	igual = igual;
                    }
                }
                else
                {
                	vazio = vazio;
                }
            }
            if (vazio==0)
		    {
		    	retorno = ESTRUTURA_AUXILIAR_VAZIA;
		    }
		    else if (igual==0)
		    {
		    	retorno = NUMERO_INEXISTENTE;
		    }
        }
	}
	
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)//OK
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])//OK
{

    int retorno = 0;
    
    if (posicao<1||posicao>10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
    {
        if (vetorPrincipal[posicao]==NULL)
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
        else
        {
        	for (int i = 0; i <= *vetorPrincipal[posicao][0]; ++i)
        	{
        		if (vetorPrincipal[posicao][i+1]!=NULL)
        		{
        			vetorAux[i] = *vetorPrincipal[posicao][i+1];		
        		}
        	}
        	retorno = SUCESSO;
        }
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
    int vaux[*vetorPrincipal[posicao][0]];

    for (int i = 0; i < *vetorPrincipal[posicao][0]; ++i)
    {
    	vaux[i] = 0;
    }

	    if (posicao<1||posicao>10)
	    {
	        retorno = POSICAO_INVALIDA;
	    }
	    else
	    {
	        if (vetorPrincipal[posicao]==NULL)
	        {
	            retorno = SEM_ESTRUTURA_AUXILIAR;
	        }
	        else
	        {
	        	
		    }
		}

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])//OK
{

    int retorno = 0;
    int k = 0, semestrutura = 0, vazio = 0;

    
	for (int i = 1; i <= TAM; ++i)
	{
		if (vetorPrincipal[i]!=NULL)
		{
			semestrutura++;
			if (vetorPrincipal[i][1]==NULL)
			{
				vazio+=0;
			}
			else
			{
				vazio++;
				for (int j = 1; j <= *vetorPrincipal[i][0]; ++j)
	    		{
	    			if (vetorPrincipal[i][j]!=NULL)
	    			{
	    				vetorAux[k] = *vetorPrincipal[i][j];
	    				k++;
	    			}
	    		}
			}
			
		}
		else
		{
			semestrutura +=0;
		}
		
	}
	if (semestrutura==0)
	{
		retorno = SEM_ESTRUTURA_AUXILIAR;
	}
	else if (vazio==0)
	{
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
	}
	else
	{
		retorno = SUCESSO;
	}

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)//OK
{

    int retorno = 0;
    

    if (posicao<1||posicao>10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
    {
        if (vetorPrincipal[posicao]==NULL)
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
        else
        {
        	int n = novoTamanho + *vetorPrincipal[posicao][0];
        	if (n < 1)
        	{
        		retorno = NOVO_TAMANHO_INVALIDO;
        	}
        	else
        	{
        		int m = n + 1;
        		vetorPrincipal[posicao] = realloc(vetorPrincipal[posicao],  m*sizeof(int *));
        		if (n > *vetorPrincipal[posicao][0])
        		{
        			for (int i = *vetorPrincipal[posicao][0] + 1; i <= m; ++i)
        			{
        				vetorPrincipal[posicao][i] = NULL;
        			}
        		}
	        		if (vetorPrincipal[posicao]==NULL)
	        		{
	        			retorno = SEM_ESPACO;
	        		}
	        		else
	        		{
	        			*vetorPrincipal[posicao][0] = n;
	        			retorno = SUCESSO;
	        		}
        	}
        }
    }

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)//OK
{

    int retorno = 0;
    int qtdelementos = 0;

    if (posicao<1||posicao>10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
    {
        if (vetorPrincipal[posicao]==NULL)
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
        else
        {
        	for (int i = 1; i <= *vetorPrincipal[posicao][0]; ++i)
        	{
        		if (vetorPrincipal[posicao][i]==NULL)
        		{
        			qtdelementos +=0;
        		}
        		else
        		{
        			qtdelementos++;
        		}
        	}
        	if (qtdelementos==0){
        		retorno = ESTRUTURA_AUXILIAR_VAZIA;
        	}
        	else{
        		retorno = qtdelementos;
        	}
	    }
	}

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()//OK
{
	int n = TAM + 1;
	vetorPrincipal = malloc(n*sizeof(int **));
	for (int i = 0; i <= TAM; ++i)
	{
		vetorPrincipal[i] = NULL;
	}
	
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()//OK
{
	for (int i = 0; i <= TAM; ++i)
	{
		if (vetorPrincipal[i]!=NULL)
		{
			for (int j = 0; j <= *vetorPrincipal[i][0]; ++j)
			{
				if (vetorPrincipal[i][j]!=NULL)
				{
					free(vetorPrincipal[i][j]);
				}
			}
			free(vetorPrincipal[i]);
		}
	}
	free(vetorPrincipal);
}
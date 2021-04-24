// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Gustavo Rodrigues de Azeredo Coutinho
//  email: gustavo1990azeredo@gmail.com
//  Matrícula: 20192160016
//  Semestre: II

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gustavoazeredo20192160016.h"

/*
## função utilizada para testes  ##
 somar = somar dois valores.
@objetivo
    Somar dois valores x e y e retonar o resultado da soma.
@entrada
    dois inteiros x e y.
@saida
    resultado da soma (x + y).
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número.
@objetivo
    calcular o fatorial de um número.
@entrada
    um inteiro x.
@saida
    fatorial de x -> x!.
 */
int fatorial(int x)
{ //função utilizada para testes.
    int fat = 1;
    return fat;
}

/*
 Q1 = validar data.
@objetivo
    Validar uma data.
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano.
    dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida;
    1 -> se data válida.
 @restrições
    Não utilizar funções próprias de string (ex: strtok);  
    pode utilizar strlen para pegar o tamanho da string.
 */
int q1(char *data)
{
    
    int iDia, iMes, iAno, size;
    char sDia[]="du", sMes[]="du", sAno[]="mcdu";
    int i=0, j=0, k=0;

    size = strlen(data);

    if (data[i]!='/')
    {
    	do
		{
		   	sDia[i] = data[i];
		   	i++;
		} while (data[i]!='/');
    }
    else
    {
    	return 0;
    }

    j = i + 1;
    i = 0;

    	if (data[j]!='/')
    	{
    		do
		    {
		    	sMes[i] = data[j];
		    	i++;
		    	j++;
		    } while (data[j]!='/');
    	}
    	else
    	{
    		return 0;
    	}

    	k = j + 1;
	    i = 0;

	    	if (data[k]!='/')
	    	{
	    		do
			    {
			    	sAno[i] = data[k];
			    	i++;
			    	k++;
			    } while (data[k]!='\0');
	    	}
	    	else
	    	{
	    		return 0;
	    	}
        	
    iDia = atoi(sDia);
	iMes = atoi(sMes);
	iAno = atoi(sAno);

	if(iAno==0)
	{
		return 0;
	}
		
        if ((iAno/1000)==0&&(iAno/100)!=0)
        {
        	return 0;
        }
	       		    
		    if ((iAno/1000)==0&&(iAno/100)==0)
		    {
		    	iAno = iAno + 2000;
		    }

	    		if ((iDia>=1&&iDia<=28)&&(iMes>=1&&iMes<=12)&&(iAno!=0))
				{
					return 1;
				}
				else
				{
					if ((iDia==30)&&(iMes!=2)&&(iAno!=0))
					{
						return 1;
					}
					else
					{
						if ((iDia==31)&&(iMes==1||iMes==3||iMes==5||iMes==7||iMes==8||iMes==10||iMes==12)&&(iAno!=0))
						{
							return 1;
						}
						else
						{
							if ((iDia==29)&&(iMes==2)&&((iAno%4==0&&iAno%100!=0)||iAno%400==0))
							{
								return 1;
							}
							else
							{
								if ((iDia==29)&&(iMes>=1&&iMes<=12&&iMes!=2)&&(iAno!=0))
								{
									return 1;
								}
								else
								{
									return 0;
								}
							}
						}
					}
				}
}

/*
 Q2 = diferença entre duas datas.
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas.
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. 
    Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. 
    Na chamada da função deve passar o valor -1 para os três.
 @saida
    1 -> cálculo de diferença realizado com sucesso;
    2 -> datainicial inválida;
    3 -> datafinal inválida;
    4 -> datainicial > datafinal.
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

    //calcule os dados e armazene nas três variáveis a seguir.
    int nDias, nMeses, nAnos;

    int iDiain, iMesin, iAnoin;
    int iDiafin, iMesfin, iAnofin;
    int iDatain, iDatafin;

    if (q1(datainicial) == 0)
    {
        return 2;
    }
    else
    {
    	if (q1(datafinal) == 0)
		{
		   	return 3;
		}
		else
		{
			sscanf(datainicial,"%d/%d/%d",&iDiain,&iMesin,&iAnoin);

			if ((iAnoin/1000)==0&&(iAnoin/100)==0)
			{
			   	iAnoin = iAnoin + 2000;
			}

			iDatain = ((((iAnoin*100)+iMesin)*100)+iDiain);

			   	sscanf(datafinal,"%d/%d/%d",&iDiafin,&iMesfin,&iAnofin);

			    if ((iAnofin/1000)==0&&(iAnofin/100)==0)
				    {
				    	iAnofin = iAnofin + 2000;
				    }

				    iDatafin = ((((iAnofin*100)+iMesfin)*100)+iDiafin);

			if(iDatain>iDatafin)
			{
				return 4;
			}
			else
			{
				nDias = iDiafin - iDiain;
			    nMeses = iMesfin - iMesin;
			    nAnos = iAnofin - iAnoin;

			    *qtdDias = nDias;
			    *qtdAnos = nAnos;
			    *qtdMeses = nMeses;

			    return 1;
			}
		}
    }

    /*mantenha o código abaixo, para salvar os dados
    nos parâmetros da função.
    */
    

    //coloque o retorno correto.
    //return 1;
}

/*
 Q3 = encontrar caracter em texto.
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto.
 @entrada
    Uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não.
    Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
    Se isCaseSensitive != 1, a pesquisa não deve considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0, size=0;

    size = strlen(texto);

    if (isCaseSensitive==1)
    {
    	for (int i = 0; i < size; ++i)
	    {
	    	if (texto[i]==c)
	    	{
	    		qtdOcorrencias++;
	    	}
	    }
    }
    else
    {
    	for (int i = 0; i < size; ++i)
	    {
	    	if (texto[i]==c||texto[i]==c-32)
	    	{
	    		qtdOcorrencias++;
	    	}
	    }
    }

	return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes),
    que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posições deve ser preenchido com cada entrada e saída correspondente...
    Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto...
    e na posição 1, deve ser preenchido com o índice de fim da ocorrencias...
    Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente...
    Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera"...
    Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1;
        O retorno da função, n, nesse caso seria 1.
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0, sizetexto = 0, sizebusca = 0, incremento = 0;
    int p=0, i=0, pinicial=0, pfinal=0;

    sizebusca = strlen(strBusca);
    sizetexto = strlen(strTexto);

    char aux[sizebusca];

    for (i = 0; i < sizebusca; ++i)
    {
    	aux[i] = 0;
    }

    	for (i = 0; i < sizetexto; ++i)
    	{
    		incremento = i;

    		for (int j = 0; j < sizebusca; ++j)
    		{
    			aux[j] = strTexto[incremento];
    			incremento++;
    		}
	    		if (strcmp(aux,strBusca))
	    		{
	    			qtdOcorrencias = qtdOcorrencias;
	    		}
	    		else
	    		{
	    			pinicial = incremento - sizebusca + 1;
	    			pfinal = incremento;
	    			posicoes[p] = pinicial;
	    			posicoes[p+1] = pfinal;
	    			qtdOcorrencias++;
	    			p = p+2;
	    		}
    	}

    return qtdOcorrencias;
}

/*
 Q5 = inverte número.
 @objetivo
    Inverter número inteiro.
 @entrada
    uma int num.
 @saida
    Número invertido.
 */

int q5(int num)
{
	int numinv=0, qtddig=0, i=0, aux=0;

	aux = num;

	do
	{
		aux = (aux/10);
		qtddig++;

	} while (aux!=0);

		int v[qtddig];
		aux = num;

		for (int i = 0; i < qtddig; ++i)
		{
			v[i] = (aux%10);
			aux = (aux/10);
		}
		
			for (int i = 0; i < qtddig; ++i)
			{
				numinv = ((numinv + v[i]) * 10);
			}

			num = (numinv/10);

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro.
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base.
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias=0, aux=0, qtddig=0;

    aux = numerobase;

    do
	{
		aux = (aux/10);
		qtddig++;

	} while (aux!=0);

		int v[qtddig];
		aux = numerobase;

		for (int i = 0; i < qtddig; ++i)
		{
			v[i] = (aux%10);
			aux = (aux/10);
		}

			for (int j = 0; j < qtddig; ++j)
			{
				aux = 0;
				for (int k = j; k < qtddig; ++k)
				{
					aux = (aux + v[k]) * 10;
					if (numerobusca==(aux/10))
					{
						qtdOcorrencias++;
					}
					else
					{
						qtdOcorrencias = qtdOcorrencias;
					}
				}
			}

	return qtdOcorrencias;
}
 
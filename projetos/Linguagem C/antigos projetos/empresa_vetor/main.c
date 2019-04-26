/* Numa fabrica trabalham homens e mulheres divididos em 3 classes:

	A -> os que fazem atÃ© 30 peÃ§as por mÃªs
	B -> os que fazem de 31 a 35 peÃ§as por mÃªs
        C-> os que fazem mais de 35 peÃ§as por mÃªs

A classe A, recebe salÃ¡rio minimo.
A classe B, recebe salÃ¡rio mÃ­nimo mais 3% do salÃ¡rio mÃ­nimo por peÃ§a, acima dos 30 iniciais.
A classe C, recebe salÃ¡rio mÃ­nimo e mais 5% do salÃ¡rio minimo por peÃ§as acima das 30 iniciais.

FaÃ§a um algoritmo que:
	
	A) Leia as vÃ¡rias linhas contendo uma:

		-O nÃºmero do empregado.
		-O nÃºmero de peÃ§as fabricadas por mÃªs
		-O sexo do empregado
	B) Calcule e escreva:
		-O salÃ¡rio de cada empregado
		-O total da folha mensal do pagamento
		-O nÃºmero total de peÃ§as fabricadas por mÃªs
		-A mÃ©dia de peÃ§as fabricadas por homens e por mulheres
		-O nÃºmero de operÃ¡rios(a) de maior salÃ¡rio. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define minimo 954
#define max 4
int main(int argc, char** argv)
{
        setlocale(LC_ALL, "Portuguese");
	int id[max], pecas[max];
	int i,controle_10 = 0,controle_20 = 0, codigo_masculino = 0, codigo_feminino = 0,pecas_homens=0,homens = 0, media_homem;
	int controle = 0, k;
	char sexo[max];
	float salario[max];
	float salario_total = 0.0, pecas_total = 0.0, media_pecas, media_salario;
	float maior_masculino = 0, maior_feminino = 0;
	
	for(i=0;i<max;i++)
	{
		printf("Digite o ID: ");
		scanf(" %d", &id[i]);
		while(id[i]<0)				//verificaÃ§Ã£o de ID somente se pode digitar ID positivo
		{
			printf("Valor de ID invÃ¡lido.\nDigite um valor vÃ¡lido: ");
			scanf(" %d", &id[i]);
		}
                for(k=i;k>0;k--)
                {
                    if(id[i]==id[k-1])
                    {
                        printf("Já há alguem com este ID.\nPor favor digite outro: ");
                        scanf(" %d", &id[i]);
                    }
                }
		
		printf("Digite a quantidade de peÃ§as produdizadas por este funcionario: ");
		scanf(" %d", &pecas[i]);
		while(pecas[i]<0)			//verificaÃ§Ã£o de peÃ§as para haver apenas valores maiores que 0
		{
			printf("Valor de peÃ§as invÃ¡lido.\nDigite um valor vÃ¡lido: ");
			scanf(" %d", &pecas[i]);
		}
				
		printf("Digite o sexo deste funcionario (M/F): ");
		scanf(" %c", &sexo[i]);
		while(sexo[i]!='m' && sexo[i]!='M' && sexo[i]!='f' && sexo[i]!='F')
		{
			printf("Digite um valor para sexo vÃ¡lido.\nDigite(M/F): ");
			scanf(" %c", &sexo[i]);
		}
	}
	for(i=0;i<max;i++)
	{
		if(pecas[i]<31)
			salario[i]=minimo;
		else
		{
			if(pecas[i]<36)
				salario[i] = minimo + (minimo * 0.03 * (pecas[i] - 30));
			else
				salario[i] = minimo + (minimo * 0.05 * (pecas[i] - 30));
		}
	}
	for(i=0;i<max;i++)
	{
		salario_total = salario_total + salario[i];
		pecas_total = pecas_total + pecas[i];
	}

	//bloco de calculo da media de salario e peÃ§as produzidas por todos os funcionario
	media_pecas = pecas_total/max;
	media_salario = salario_total/max;
	printf("Media de salario do total de funcionÃ¡rios: %.2f.\nMedia de peÃ§as produziadas por todos os funcionarios: %.2f",media_salario,media_pecas);

        //bloco que calcula a produÃ§Ã£o dos funcuionarios
	printf("\nLista de funcionarios que produziram 10%% a mais que a mÃ©dia de funcionarios\n:");
	for(i=0;i<max;i++)
	{
		if(pecas[i] >= media_pecas*1.1)
		{
			printf("ID: %d\n",id[i]);
			controle_10 = 1;
		}		
	}
	if(controle_10 == 0)
		printf("\nNinguem produziu 10%% a mais que a mÃ©dia (parametros entre 10%% a 19%%");
	printf("\nLista de funcionarios que produziram 20%% a menos que a mÃ©dia de funcionarios\n:");
	for(i=0;i<max;i++)
	{
		if(pecas[i] <= media_pecas*1.2)
			printf("ID: %d\n",id[i]);
	}

//bloco que calcula o homem e a mulher que mais produziram
	for(i=0;i<max;i++)
	{
		if(pecas[i] > maior_masculino && (sexo[i]=='m' || sexo[i]=='M'))
		{
			maior_masculino = pecas[i];
			codigo_masculino = id[i];
		}
		if(pecas[i] > maior_feminino && ( sexo[i] == 'f' || sexo[i] == 'F'))
		{
			codigo_feminino = id[i];
			maior_feminino = pecas[i];
		}
	}
	printf("O homem que mais produziu peÃ§as tem ID: %d.\nA mulher que mais produziu peÃ§as tem ID: %d\n",codigo_masculino,codigo_feminino);

//bloco que calcula a media de peÃ§as produzidas por homens e as mulheres que produziram mais que essa media
	for(i=0;i<max;i++)
	{
		if(sexo[i]=='m' || sexo[i]=='M')
		{
			pecas_homens = pecas_homens + pecas[i];
			homens++;
		}
	}
	media_homem = pecas_homens/homens;
	printf("ID de mulheres que fabricaram mais que a mÃ©dia de homens: \n");
	for(i=0;i<max;i++)
	{
		if(sexo[i]=='f' || sexo[i]=='F')
		{
			if(pecas[i] > media_homem)
			{
				printf("ID: %d\n",id[i]);
				controle=1;
			}
		}

	}
	if(controle==0)
		printf("\nNÃ£o ouveram mulheres que produziram mais que a mÃ©dia dos homens\n\n");
        return 0;
}


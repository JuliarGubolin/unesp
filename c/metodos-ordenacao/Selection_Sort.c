/*Ordena��o por sele��o*/
/*� escolhida uma posi��o e esta � comparada com as outras, de forma a encontrar a posi��o com o menor valor. Ap�s isso, 
� trocada a posi��o.*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
void selecao(int vet[], int n)
{
	int menor, aux;
	for(int i=0; i<n-1;i++)
	{
		menor = i;
		for(int j=i+1;j<n;j++)
		{
			if(vet[menor]>vet[j]){
				menor = j;
			}
		}
		if(i!=menor)
		{
			aux = vet[i];
			vet[i] = vet[menor];
			vet[menor] = aux; 
		}
	}
	
}
int main ()
{
	setlocale(LC_ALL,"portuguese");
	
	int n=9;
	int vetor[n] = {3, 6, 5, 7, 4, 1, 2, 9, 8};
	
	selecao(vetor, n);
	
	for(int i=0;i<n;i++)
	{
		printf("%d - ",vetor[i]);	
	}
	
	return 0;
	
}
/*Pseudocódigo para busca linear:
função busca_linear(tamanho, chave, vetor[]: inteiro): inteiro
	início
	i: inteiro
	para i de 0 até tamanho faça
		se vetor[i] == chave então
			retorne i
		fim se
	fim para
	retorne NIL
	fim função
*/
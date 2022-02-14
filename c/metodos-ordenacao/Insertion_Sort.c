/*Ordenação por inserção*/
/*O segundo elemento será comparado com o anterior e, caso seja menor, será trocado.*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
void insercao(int vet[], int n)
{
	int i, j, num_atual;
	for(i=1;i<n;i++)
	{
		num_atual = vet[i]; //num_atual = 3
		j = i-1; //j==0
		
		while((j>=0) && (num_atual< vet[j]))
		{
			vet[j+1] = vet[j];
			j--; //j=-1;
		}
		vet[j+1] = num_atual; //vet[0] = num_atual = 3
	}
	

}
int main ()
{
	setlocale(LC_ALL,"portuguese");
	
	int n=5;
	int vetor[n] = {5, 3, 10, 1, 6};
	
	insercao(vetor, n);
	
	for(int i=0;i<n;i++)
	{
		printf("%d - ",vetor[i]);	
	}
	
	return 0;
}
	

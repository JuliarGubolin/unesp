/*Ordena��o por bolha*/
/*Ir� trocar os valores caso a posi��o escolhida seja maior que a pr�xima*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
void bolha(int vet[], int n)
{
	int i, j, aux;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(vet[j]<vet[j+1])
			{
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}
			
		}
	}
}
int main ()
{
	setlocale(LC_ALL,"portuguese");
	
	int n=9;
	int vetor[n] = {3, 6, 5, 7, 4, 1, 2, 9, 8};
	
	bolha(vetor, n);
	
	for(int i=0;i<n;i++)
	{
		printf("%d - ",vetor[i]);	
	}
	
	return 0;
	
}

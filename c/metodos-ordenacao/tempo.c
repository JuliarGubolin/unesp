#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<sys/time.h>
#include<stdbool.h>
#define m1 10
#define m2 1000
#define m3 100000
#define m4 10000000

void criar_vetor (long int	v1[],long int v2[],long int v3[], long int v4[])
{
	int i=0;
	while(i<m1)
	{
		v1[i] = rand()%m1;i++;
	}
	i=0;
	while(i<m2)
	{
		v2[i] = rand()%m2;i++;
	}
	i=0;
	while(i<m3)
	{
		v3[i] = rand()%m3;i++;
	}
  i=0;
	while(i<m4)
	{
		v4[i] = rand()%m4;i++;
	}
}

void BubbleSort(long int vetor[], int tamanho){
	int memoria, troca, i, j;
	troca=1; /*A variável "troca" será a verificação da troca em cada passada*/
	for(j=tamanho-1; (j>=1) && (troca==1); j--){
		troca=0; /*Se o valor continuar 0 na próxima passada quer dizer que não houve troca e a função é encerrada.*/
		for(i=0; i<j; i++){
				if(vetor[i]>vetor[i+1]){
					memoria=vetor[i];
					vetor[i]=vetor[i+1];
					vetor[i+1]=memoria;
					troca=1; /*Se houve troca, "troca" recebe 1 para continuar rodando.*/
			}
		}
	}
}

void insertion_sort(int tabela[], int largura){
	int i, memoria, contador; 
	bool marcador; 
	for(i=1; i<largura; i++){
		memoria = tabela[i];
		contador = i-1;
		do{
			marcador = false;
			if(tabela[contador] > memoria){
				tabela[contador+1] = tabela[contador];
				contador--;
				marcador = true;
			}
			if(contador < 0) marcador = false;
		}while(marcador);
	}
	tabela[contador+1] = memoria;
}

void merge(int vetor[], int comeco, int meio, int fim) {

    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}


void mergeSort(int vetor[], int comeco, int fim){

    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);

    }
}

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n <= 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

//Minha escolha
void selection(int *pVetor, int max2)
{
    int vMenor,vAux,vTemp,vTroca;

    for(vAux=0; vAux < max2-1; vAux++)
    {
        vMenor = vAux;

        for (vTemp=vAux+1; vTemp < max2; vTemp++)
        {
            if (pVetor[vTemp] < pVetor[vMenor])
            {
                vMenor = vTemp;
            }
        }
        if (vMenor != vAux)
        {
            vTroca = pVetor[vAux];
            pVetor[vAux] = pVetor[vMenor];
            pVetor[vMenor] = vTroca;
        }
    }
}

int main ()
{   
	setlocale (LC_ALL, "portuguese");
	
	long int v1[m1], v2[m2], v3[m3], *v4;
	int i;
   double tempo;
   struct timeval inicio, fim;
	
   if (!(v4 = malloc(m4 * sizeof(*v4))))
        exit(1);
	criar_vetor(&v1[0], &v2[0], &v3[0], &v4[0]);

   gettimeofday(&inicio, NULL);

   BubbleSort(&v4[0],m4);
   	
   gettimeofday(&fim, NULL);
   tempo = (fim.tv_sec - inicio.tv_sec) + ((fim.tv_usec - inicio.tv_usec)/1000000.0);
	printf("O tempo foi de %lf segundos",tempo);
	return 0;
}

//Declaração de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
//Definição global do tamanho do vetor de struct BigInt
#define TAM 200000

//Estrutura que representa o número e suas divisões high e low
//Definida no enunciado do projeto
typedef struct biggo{ 
  int high; 
  int low; 
}BigInt;

//Função que irá comparar as partes HIGH de dois valores
//Caso sejam iguais, ele irá comparar pela parte LOW
/*Esta função tem por objetivo 'auxiliar' os métodos a ordenar,
já que ambos os métodos de ordenação comparam posições do vetor*/
int comparar_BigInts(BigInt um, BigInt dois){
  //Caso o valor high do primeiro número for maior que o 
  //high do segundo, retornamos 1.
  if(um.high>dois.high){
  	return 1; 
  }
  //Caso o valor high do segundo número for maior que o 
  //high do primeiro, retornamos 0.
  else if(um.high<dois.high){
  	return 0; 
  }
  //Caso os valores sejam iguais, é necessário comparar o LOW dos valores
  else{
    //Caso o LOW do primeiro número for maior que o do segundo, retornamos 1
  	if(um.low>dois.low){
  		return 1;
	  } 
    //Caso o LOW do segundo número for maior que o do primeiro, retornamos 0
  	else if(um.low<dois.low){
   		return 0;
	  }	//Caso ambos os valores sejam iguais
  	else{
  		return 2;	
	  }
  }
}
//Algoritmo de ordenação Shell Sort (Knuth)
//Recebe como parâmetro o vetor que deve ser ordenado
//Retorna o tempo necessário para a ordenação do vetor
double shellsort(BigInt vetor[TAM]){ 
  //Declaração das variáveis da estrutura que calcula o tempo necessário para a ordenação
  struct timeval inicio, fim;
  //Variáveis utilizadas nos laços de repetição
  int i, j, k, l;
  //Variável auxiliar para a ordenação
  BigInt valor; 
  //Variável que receberá o tempo necessário para ordenação
  double duracao;
  k = 1;
  //Início do algoritmo Shell Sort e da contagem do tempo (em segundos)
  gettimeofday(&inicio, NULL);
  while (k < TAM/2){
    k = 3*k + 1; 
  }
  while (k != 1){ 
    k = k/3; 
    //Ordena cada divisão do vetor 
    for (l=0; l<k; l++){ 
      //Insertion Sort dentro do Shell Sort
      for (i=l+k; i<TAM; i=i+k){ 
          valor = vetor[i];
          j = i;
          for(j=i;(j-k>=0)&& ((comparar_BigInts(valor, vetor[j-1])) == 0);j=j-k){ 
            vetor[j] = vetor[j-k];
          }
          vetor[j] = valor;
        }
    }
  }
  //Fim do algoritmo e da contagem do tempo
  gettimeofday(&fim, NULL);
  //Cálculo do tempo total para a ordenação do vetor 
  duracao = (fim.tv_sec - inicio.tv_sec) + ((fim.tv_usec - inicio.tv_usec)/1000000.0);
  return duracao;
}

//Algoritmo de ordenação Selection Sort
//Recebe como parâmetro o vetor que deve ser ordenado
//Retorna o tempo necessário para a ordenação do vetor
double selectionsort(BigInt vetor[TAM]){ 
  int i, j, menor;
  BigInt aux;
  //Variável que receberá o tempo necessário para ordenação
  double duracao;
  struct timeval inicio, fim;
  //Início do algoritmo Selection Sort e da contagem do tempo (em segundos)
  gettimeofday(&inicio, NULL);
  for (i=0; i<TAM-1; i++){  
    menor = i;
    for (j=i+1; j<TAM; j++)
      if ((comparar_BigInts(vetor[j], vetor[menor])) == 0)
        menor = j;
        if (menor != i){ 
          aux = vetor[i];
          vetor[i] = vetor[menor];
          vetor[menor] = aux;
        }
  }
  //Fim do algoritmo e da contagem do tempo
  gettimeofday(&fim, NULL);
  //Cálculo do tempo total para a ordenação do vetor 
  duracao = (fim.tv_sec - inicio.tv_sec) + ((fim.tv_usec - inicio.tv_usec)/1000000.0);
  return duracao;
}
//Função principal MAIN
int main(void){
  /*Declaração dos vetores do tipo BigInt, os quais irão
  receber os dados do arquivo*/
  BigInt leitura[TAM], leitura2[TAM];
  int i=0;
  //Variáveis que receberão o tempo de ordenação utilizando os respectivos algoritmos
  double shellT, selectionT;
  //Ponteiros para os arquivos de entrada (arqRead) e saída (arqRWrite)
  FILE *arqRead, *arqWrite;
  //Verificando se os arquivos podem ser abertos corretamente
  if((arqRead = fopen("bigint.dat", "r")) == NULL || (arqWrite = fopen("shell.dat", "w")) == NULL){
      printf("Erro na abertura do(s) arquivo(s).");
      exit(1);
  }
  //Lendo o arquivo de entrada e salvando suas informações nos vetores BigInt
  while(!feof(arqRead)){
    fscanf(arqRead, "%d %d", &leitura[i].high, &leitura[i].low);
    leitura2[i].high = leitura[i].high;
    leitura2[i].low = leitura[i].low;
    i++;
  }
  //Chamando as funções que correspondem aos 2 algoritmos de ordenação
  //As funções retornam a duração da ordenação (em segundos)
  shellT = shellsort(leitura);
  selectionT = selectionsort(leitura2);
  printf("Tempo ShellSort: %f.\nTempo SelectionSort: %f\n", shellT, selectionT);
  //Escrevendo no arquivo de saída o vetor ordenado
  for(i=0;i<TAM;i++){
    fprintf(arqWrite, "%d %d\n", leitura[i].high, leitura[i].low);
  }
  //Finalizando o programa fechando os arquivos e retornando 0
  fclose(arqRead);
  fclose(arqWrite);
  return 0;
}
//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Declaração das funções que serão usadas 
void combinacaoPrincipal(int decompor[], int vetAux[], int ini, int fim, int posAtual, int r, int valor, int *auxiliar);
void combinacaoAuxiliar(int decompor[], int n, int r, int valor, int *auxiliar);
int *vetor(int tam);
 
/*Função que faz as somas sucessivas de r valores, 
sem repetir, e coloca no vetor vetAux, apenas se 
o posAtual (posição atual no vetor) for igual a quantidade 
de espaços totais do vetor (significando que ele foi completado).
Se a soma que foi colocada no vetor for igual ao valor que deve ser decomposto,
representado pela variável 'valor', a variável auxiliar é somada em 1.*/ 
/*ini e fim representam o índice inicial e final, respectivamente, do vetor decompor
decompor é o vetor de entrada e vetAux é o vetor que salva a combinação de valores
r é o tamanho da combinação que deve ser mostrada
e posAtual é a posição atual no vetor vetAux
auxiliar é a variável que contabiliza quantas combinações formam o valor especificado
*/
void combinacaoPrincipal(int decompor[], int vetAux[], int ini, int fim, int posAtual, int r, int valor, int *auxiliar)
{
    int j, i;
    //Completou a quantidade de combinações possíveis com r valores
    if (posAtual == r){
        int soma = 0;
        for (j=0; j<r; j++){
            soma = soma + vetAux[j];
        }
        if(soma == valor){
          *auxiliar = *auxiliar + 1;
        }
        return;
    }
    //Região da função que substitui o índice por todos os elementos possíveis. A condição
    //"fim-i + 1> = r-posAtual" combina os elementos nas posições que ainda
    //estão vazias no vetor 
    for (i=ini; i<=fim && fim-i+1 >= r-posAtual; i++)
    {
        vetAux[posAtual] = decompor[i];
        combinacaoPrincipal(decompor, vetAux, i+1, fim, posAtual+1, r, valor, auxiliar);
    }
}

//Função para chamar a função principal e criar o vetor que salva todas as combinações
//do tamanho passado pela variável 'r'
void combinacaoAuxiliar(int decompor[], int n, int r, int valor, int *auxiliar)
{
    //Vetor temporário para armazenar todas as operações
    int vetAux[r];
    combinacaoPrincipal(decompor, vetAux, 0, n-1, 0, r, valor, auxiliar);
}

//Função para criar o vetor no tamanho indicado pelo usuário
//nas variáveis n ou m. O vetor n1 indica os números a serem decompostos e o 
//vetor m1 indica os números que podem ser utilizados para decompor
int *vetor(int tam){
  //PTR é o ponteiro que irá armazenar os 'tam' valores.
  int *ptr = (int*)malloc(tam * sizeof(int));
  for (int i = 0; i < tam; i++){
      printf("Digite os %d numeros: ", tam);
      scanf("%d", &ptr[i]);
  }
  return ptr;
}
//Função principal
int main(void){
  //Declaração de variáveis
  int n, m, i=0, r, auxiliar=0;

  //Valores que o usuário deve inserir 
  printf("Quantidade de números a serem decompostos e quantidade de números disponíveis para decompor: ");
  scanf("%d %d", &n, &m);
  //Verificando se os valores digitados estão no intervalo correto 
  if((n > 100 || n < 0) || (m > 20 || m < 5)){
    printf("Valor(es) no intervalo inválido.");
    exit(1);
  }
  //Números que devem ser usados para decompor
  int *m1 = vetor(m);
  //Números que devem ser decompostos em outros
  int *n1 = vetor(n);
  //Loop para decompor todos os valores indicados pelo usuário
  while(i < n){
    //A variável auxiliar deve ser zerada para iniciar a contagens de combinações
    //possíveis para o próximo valor salvo no vetor n1
        auxiliar = 0;
        r = 1;
        //Loop para decompor o valor que está no vetor n1 na posição i (n1[i])
        //Passando por todos os valores de m1
        while(r < m+1){
            combinacaoAuxiliar(m1, m, r, n1[i], &auxiliar);
            r++;
        }
        i++;
        //Mostrando na tela quantas combinações são possíveis para gerar o valor enviado
        printf("%d\n", auxiliar);
    }
    //Fim do programa
  return 0;
}
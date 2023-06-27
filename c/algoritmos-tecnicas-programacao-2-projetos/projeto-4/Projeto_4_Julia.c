//Bibliotecas necessárias
#include<stdio.h>
#include<stdlib.h>
//Variável KL com a dimensão das matrizes A, B
//Tanto o número de linhas quanto de colunas deve estar entre 100 e 10000
#define KL 10000

/*Struct para o elementos da lista, que representa o elemento da matriz 
Ela possui os itens: valor(valor na matriz), linha e coluna, os ponteiros 
para o próximo na linha e na coluna e find (marcação para verificar se já passou pela célula)*/
typedef struct listElem{
  int linha, coluna, find;
  double valor;
  struct listElem *Lprox;
  struct listElem *Cprox;
}ListElem;

/*Struct que representa a matriz de ponteiros.
Ela possui os itens: um ponteiro linha, que irá apontar para 
o elemento no mesmo valor de linha e um ponteiro coluna, que irá, 
da mesma forma, apontar para o elemento com o mesmo valor de coluna*/
typedef struct matrizPont{
  ListElem *linha[KL];
  ListElem *coluna[KL];
}MP;
/*Função para inserir um elemento na lista e, consequentemente, 
fazer com que ele seja apontado pelos ponteiros da linha e da coluna
Ela recebe os parâmetros: matrizPont M (a struct que possui os ponteiros 
para as linhas e colunas), ela sempre receberá A ou B, dependendo da matriz 
onde serão adicionados os elementos, lin (linha), col (coluna), val (valor)*/
ListElem* inserir(MP *M, int lin, int col, double val){
  //Alocação de memória para o novo elemento da lista
  ListElem *novo = malloc(sizeof(ListElem));
  //Criação de um ponteiro do tipo ListElem (elemento da lista) par auxiliar na inserção
  ListElem *aux;
  //Atribuindo os valores devidos aos campos do novo listElem
  novo->coluna=col;
  novo->linha=lin;
  novo->valor=val;
  novo->find=0;
  novo->Lprox=NULL;
  novo->Cprox=NULL;

  /*Se a linha na qual precisa ser inserido o elemento estiver vazia, 
  a linha da posição em questão apontará para o novo elemento.*/
  if(M->linha[lin]==NULL){
    M->linha[lin]=novo;
  }
  //Se não, ocorrerá uma busca para verificar a próxima posição vazio na matriz (struct matrizPont)
  else{
    aux=M->linha[lin];
    while(aux->Lprox!=NULL){
      aux=aux->Lprox;
    }
    aux->Lprox=novo;
  }
  /*Se a coluna na qual precisa ser inserido o elemento estiver vazia, 
  a coluna da posição em questão apontará para o novo elemento.*/
  if(M->coluna[col]==NULL){
    M->coluna[col]=novo;
  }
  //Se não, ocorrerá uma busca para verificar a próxima posição vazia na matriz (struct matrizPont)
  else{
    aux=M->coluna[col];
    while(aux->Cprox!=NULL){
      aux=aux->Cprox;
    }
    aux->Cprox=novo;
  }
  //Ao final, retorna o novo elemento à função principal
  return novo;
}

//Função principal (MAIN)
int main(void){
  FILE *arqWrite;
  //Variável que receberá de entrada o valor a ser salvo na lista
  double val;
  //Auxiliares para percorrer a lista
  ListElem *auxA, *auxB, *auxC;
  //Inteiros para receber os valores do teclado
  //M: tamanho da matriz B
  //N: tamanho da matriz A
  //I: para as iterações
  //lin e col: linha e coluna onde 'val' será colocado
  int find, m, n, i, lin, col;
  //Variáveis do tipo MP para cada matriz 
  MP A, B, C;
  //Todos os elementos da struct de matriz A e B devem ser inicializados com NULL
  for(i=0;i<KL;i++){
    A.linha[i]=NULL;
    B.linha[i]=NULL;
  }
  //Verificando se o arquivo pode ser aberto para escrita corretamente.
  //Senão, o programa é encerrado
  if((arqWrite = fopen("matriztC.txt", "w")) == NULL){
      printf("Erro na abertura do arquivo.");
      exit(1);
  }
  //Recebendo de entrada os valores não nulos da matriz A e da matriz
  //B, respectivamente
  scanf("%d %d",&n, &m);
  //Inserindo na lista e conectando a struct da matriz A os trios de
  //valores: valor, linha e coluna 
  i=0;
  while(i<n){
    scanf("%lf %d %d", &val, &lin, &col);
    inserir(&A, lin, col, val);
    i++;
  }
  //Inserindo na lista e conectando a struct da matriz B os trios de
  //valores: valor, linha e coluna 
  for(i=0;i<m;i++){
    scanf("%lf %d %d", &val, &lin, &col);
    inserir(&B, lin, col, val);
  }
  /*Estrutura de repetição que tem como objetivo verificar os valores 
  não nulos nas matrizes A e B e coloca-los na matriz C. Se existirem posições
  não nulas iguais em ambas as matrizes (mesma linha e coluna), os valores serão
  somados e colocados na matriz C. */
  for(i=0;i<KL;i++){
    find=0;
    //Armazenando a linha de A na posição i em uma variável
    auxA=A.linha[i];
    //Enquando houverem linhas de A não vazias
    while(auxA!=NULL){
      //Recebemos a linha de B na posição i
      auxB=B.linha[i];
      //Enquando houverem linhas de B não vazias
      while(auxB!=NULL){
        //Se encontrarmos 2 valores de coluna não nulos e iguais nas matrizes A e B,
        //Inserimos a soma deles na mesma posição (coluna) da matriz C
        if(auxA->coluna==auxB->coluna){
          inserir(&C, i, auxA->coluna, auxA->valor+auxB->valor);
          //Find recebe 1
          find=1;
          auxB->find=1;
        }
        auxB=auxB->Lprox;
      }
      //Caso tenhamos encontrado uma linha não nula na matriz A
      //mas sem correspondência em B, salvamos em C apenas o valor que estava 
      //em A (sem somar nada)
      if(!find){
        inserir(&C, i, auxA->coluna, auxA->valor);
      }
      auxA=auxA->Lprox;
    }
    auxB=B.linha[i];
    //Caso tenhamos encontrado uma linha não nula na matriz B
    //mas sem correspondência em A, salvamos em C apenas o valor que estava 
    //em B (sem somar nada) na posição indicada
    while(auxB!=NULL){
      if(!auxB->find){
        inserir(&C, i, auxB->coluna, auxB->valor);
      }
      auxB=auxB->Lprox;
    }
  }
  /*Estrutura de repetição para percorrer a matriz C e 
  escrever no arquivo o valor da posição (independente se estiver 
  somado com outro valor ou não), o valor da linha e da coluna*/
  i=0;
  while(i < KL){
    auxC=C.linha[i];
    while(auxC!=NULL){
      fprintf(arqWrite, "%.1f %d %d ",auxC->valor,auxC->linha,auxC->coluna);
      auxC=auxC->Lprox;
    }
    i++;
  }
  //Finaliza o programa fechando o arquivo e retonando 0
  printf("Verifique o resultado no arquivo 'matrizC.txt'.\n");
  fclose(arqWrite);
  return 0;
}
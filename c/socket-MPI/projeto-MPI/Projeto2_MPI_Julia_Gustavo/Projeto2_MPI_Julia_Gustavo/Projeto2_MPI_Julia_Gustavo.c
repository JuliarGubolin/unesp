#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include <stddef.h>

typedef struct Pixel{
    int x, y, R, G, B;
} Pixel;

//Gera a matriz com os valores R, G, B do fundo em 0, 0, 0, e a borda com valor 127, 127, 127
void inicializaMatriz(int lin, int col, Pixel **matriz){
	int i, j;
  for (i = 0; i < lin; i++){
    for (int j = 0; j < col; j++){
      if(i == 0 || j == 0 || i == lin-1 || j == col-1){//Gerando a borda
        Pixel borda = {i, j, 127, 127, 127};
        matriz[i][j] = borda;
      }
      else{//Gerando o fundo
        Pixel fundo = {i, j, 0, 0, 0};
        matriz[i][j] = fundo;
      }
    }
  }
  return;
}

//Aloca os pontos fixos na matriz final com a borda
void alocaFixosMatriz(int lin, int col, Pixel **matriz, int qtd_pf, Pixel pontos_fixos[], int pos){
  for (int i = 0; i < qtd_pf; i++){
    //Usa a posição para verificar qual é a posição real do pixel em relação a essa sub-matriz
    //O X do ponto fixo + 1 - a posição real sfimo possivel nessa sub-matriz ...
    //significa que esse ponto pertence a essa partição da matriz total 
    if(pontos_fixos[i].x+1-pos >= 1 && pontos_fixos[i].x+1-pos <= lin-1 && pontos_fixos[i].y+1 < col){
      matriz[(pontos_fixos[i].x)+1-pos][pontos_fixos[i].y+1].R = pontos_fixos[i].R;
      matriz[(pontos_fixos[i].x)+1-pos][pontos_fixos[i].y+1].G = pontos_fixos[i].G;
      matriz[(pontos_fixos[i].x)+1-pos][pontos_fixos[i].y+1].B = pontos_fixos[i].B;
    }
  }
  return;
}

int main(int argc, char **argv) {
  MPI_Status status;//Status do MPI
  double ini, fim;//Cronometro
  printf("\nServidor Ligado! Recebendo clientes...\n");
  int tamanho_matriz, qtd_pf, i, j;
  //Abre o arquivo
  FILE *arq;
  if ((arq=fopen ("imagem_768x768.dat","r")) == NULL) {
    printf("Falha de abertura do arquivo");
    return 0;
  }
  int cont=0;
  //Lê primeira linha com o tamanho da matriz e a quantidade de pontos
  fscanf(arq, "%d %d ", &tamanho_matriz, &qtd_pf);
  Pixel pontos_fixos[qtd_pf];//Cria a variavel do tipo Pixel com o tamanho atrelado a quantidade de pontos fixos
  //Aloca os pontos fixos no vetor pontos_fixos
  while (!feof(arq)){	
    setbuf(stdin, NULL);
    fscanf(arq, "%d %d %d %d %d ", &pontos_fixos[cont].x, &pontos_fixos[cont].y, &pontos_fixos[cont].R, &pontos_fixos[cont].G, &pontos_fixos[cont].B);
    pontos_fixos[cont].x--;
    pontos_fixos[cont].y--;
    cont++;
  }
  fclose(arq);//Fecha o arquivo
  //Cria a matriz ponteiro de ponteiro com a borda
  Pixel **matriz;
  matriz = malloc((tamanho_matriz+2) * sizeof(Pixel*));
  for(i = 0; i < tamanho_matriz+2; i++){
    matriz[i] = malloc((tamanho_matriz+2) * sizeof(Pixel));
  }
  inicializaMatriz(tamanho_matriz+2, tamanho_matriz+2, matriz);//Inicializa a matriz
  alocaFixosMatriz(tamanho_matriz+2, tamanho_matriz+2, matriz, qtd_pf, pontos_fixos, 0);//Coloca os pontos fixos na matriz
  
  int iteracoes = 10000;//Numero de iteracoes
  
  MPI_Init(&argc, &argv);//Inicia o MPI

  //Criar datatype Pixel
  Pixel aux; //Variavel auxiliar
  int qtd_tipos_struct = 1; //Diferentes tipos de dados que a struct possui
  MPI_Datatype vetor_tipos[qtd_tipos_struct]; //Vetor da quantidade de tipos
  vetor_tipos[0] = MPI_INT; //Passa para o vetor que o unico tipo é int
  int vetor_tamanho_bloco[qtd_tipos_struct]; //Tamanho do bloco
  vetor_tamanho_bloco[0] = 5; //Armazena a quantidade de atributos da struct

  //Espaço que cada tipo da struct vai ocupar em memoria
  MPI_Aint vetor_pos_memoria[qtd_tipos_struct];
  MPI_Aint fimereco_inicio, fimereco_fim;
  MPI_Get_address(&aux, &fimereco_inicio);
  MPI_Get_address(&aux.x, &fimereco_fim);
  vetor_pos_memoria[0] = fimereco_fim - fimereco_inicio;

  //Novo tipo de dado MPI que engloba a struct Pixel
  MPI_Datatype MPI_PIXEL;
  MPI_Type_create_struct(qtd_tipos_struct, vetor_tamanho_bloco, vetor_pos_memoria, vetor_tipos, &MPI_PIXEL);//Criar o MPI_PIXEL
  MPI_Type_commit(&MPI_PIXEL); //Commita o MPI_PIXEL
  
	//Criar o grid
  int qtd_processos;
  MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
  int col_grid = qtd_processos;//col do grid
  int coords; //Localizacao do processo no grid
  int wrap = 0, reorder = 1;
  
  MPI_Comm grid; //Cria o grid
  //Alinha para poder acontecer a comunicacao
  MPI_Cart_create (MPI_COMM_WORLD, 1, &col_grid, &wrap, reorder, &grid);
  
  int id_processo;
  MPI_Comm_rank(grid, &id_processo);
  
  //Coordena o processo dentro do grid
  MPI_Cart_get (grid, 1, &col_grid, &wrap, &coords);
  
  //Comunica entre os processos superiores e inferiores
  int sup, inf;
  MPI_Cart_shift (grid, 0, 1, &sup, &inf);
  
  //Cria as submatrizes dos processos
  int lin = (tamanho_matriz/qtd_processos)+2 , col = tamanho_matriz+2;
  Pixel **sub_matriz;
  sub_matriz = malloc(lin * sizeof(Pixel*));
  for(i = 0; i < lin; i++){
    sub_matriz[i] = malloc(col * sizeof(Pixel));
  }
  for(int i=0;i<lin;i++){
	for(int j=0;j<col;j++){
		sub_matriz[i][j] = matriz[i+(id_processo*(tamanho_matriz/qtd_processos))][j];
	}
  }
  Pixel **matriz_aux;//Matriz auxiliar para salvar os resultados
  matriz_aux = malloc(lin * sizeof(Pixel*));
  for(i = 0; i < lin; i++){
    matriz_aux[i] = malloc(col * sizeof(Pixel));
  }
  Pixel borda_sup_env[col], borda_sup_rec[col]; //Borda superior enviar e receber da sub-matriz
  Pixel borda_inf_env[col], borda_inf_rec[col]; //Borda inferior enviar e receber da sub-matriz
  

  //Iteracoes
  ini = MPI_Wtime();//Ativa o cronometro
  int pos = id_processo * (tamanho_matriz/qtd_processos);
  for(int x = 0; x<iteracoes; x++){//Laco para a quantidade de iteracoes escolhidas
    if(x%200 == 0 && id_processo == 0){
      printf("\nIteracao %d\n",x+1);
    }
    for (int i = 1; i < lin-1; i++){
      for (int j = 1; j < col-1; j++){
        //Calculo dos valores
        matriz_aux[i][j].R = floor((sub_matriz[i][j].R+sub_matriz[i-1][j].R+sub_matriz[i+1][j].R+sub_matriz[i][j-1].R+sub_matriz[i][j+1].R)/5);
        matriz_aux[i][j].G = floor((sub_matriz[i][j].G+sub_matriz[i-1][j].G+sub_matriz[i+1][j].G+sub_matriz[i][j-1].G+sub_matriz[i][j+1].G)/5);
        matriz_aux[i][j].B = floor((sub_matriz[i][j].B+sub_matriz[i-1][j].B+sub_matriz[i+1][j].B+sub_matriz[i][j-1].B+sub_matriz[i][j+1].B)/5);
      }
    }
    //Pega os valores calculados e coloca na submatriz
    for (int i = 1; i < lin-1; i++){
      for (int j = 1; j < col-1; j++){
        sub_matriz[i][j].R = matriz_aux[i][j].R;
        sub_matriz[i][j].G = matriz_aux[i][j].G;
        sub_matriz[i][j].B = matriz_aux[i][j].B;
      }
    }
    //Aloca os pontos fixos na submatriz
    alocaFixosMatriz(lin, col, sub_matriz, qtd_pf, pontos_fixos, pos);
    
    //Coloca nos vetores de enviar os valores da submatriz
    for (int j = 0; j < col; j++){
      borda_sup_env[j] = sub_matriz[1][j];
      borda_inf_env[j] = sub_matriz[lin-2][j];
    }
    //Manda e recebe as linhas e bordas na parte superior
    if(sup >= 0){
      if(id_processo%2 == 0){
        MPI_Sfim(&borda_sup_env, col, MPI_PIXEL, sup, 1, grid);
        MPI_Recv(&borda_sup_rec, col, MPI_PIXEL, sup, 1, grid, &status);
      }
      else{
        MPI_Recv(&borda_sup_rec, col, MPI_PIXEL, sup, 1, grid, &status);
        MPI_Sfim(&borda_sup_env, col, MPI_PIXEL, sup, 1, grid);
      }
    }
    else{
      for (int j = 0; j < col; j++){//Caso seja a borda real, vira 127
        borda_sup_rec[j].R = 127;
        borda_sup_rec[j].G = 127;
        borda_sup_rec[j].B = 127;
      }
    }
    //Manda e recebe as linhas e bordas na parte inferior
    if(inf >= 0){
      if(id_processo%2 == 0){
        MPI_Sfim(&borda_inf_env, col, MPI_PIXEL, inf, 1, grid);
        MPI_Recv(&borda_inf_rec, col, MPI_PIXEL, inf, 1, grid, &status);
      }
      else{
        MPI_Recv(&borda_inf_rec, col, MPI_PIXEL, inf, 1, grid, &status);
        MPI_Sfim(&borda_inf_env, col, MPI_PIXEL, inf, 1, grid);
      }
    }
    else{
      for (int j = 0; j < col; j++){//Caso seja a borda real, vira 127
        borda_inf_rec[j].R = 127;
        borda_inf_rec[j].G = 127;
        borda_inf_rec[j].B = 127;
      }
    }
    for (int j = 0; j < col; j++){
      sub_matriz[0][j] = borda_sup_rec[j];
      sub_matriz[lin-1][j] = borda_inf_rec[j];
    }
  }
  
  //Envia as submatrizes para o processo 0 juntar
  if(id_processo != 0){
    MPI_Sfim(&sub_matriz[0][0], lin*col, MPI_PIXEL, 0, 1, grid);
  }
  else{
    //Cria a matriz final
    Pixel **matriz_final;
    matriz_final = malloc(tamanho_matriz * sizeof(Pixel*));//Alocacao dinamica
    for(int i = 0; i < tamanho_matriz; i++){
      matriz_final[i] = malloc(tamanho_matriz * sizeof(Pixel));
    }
    //Calcula os valores dos processos
    for(int x = 0; x < qtd_processos; x++){
      //Se nao for o processo 0
      if(x != 0){
        //Recebe o valor que sera alocado
        MPI_Recv(&sub_matriz[0][0], lin*col, MPI_PIXEL, x, 1, grid, &status);
      }
      //Aloca para a posicao final da matriz final
      for(int i = 1; i < lin-1; i++){
        for(int j = 1; j < col-1; j++){
            matriz_final[i-1+(tamanho_matriz/qtd_processos)*x][j-1] = sub_matriz[i][j];
        }
      }
    }
    //Abre e escreve no arquivo a matriz final
    if ((arq=fopen ("resultado_matriz.dat","w")) != NULL) {
        for(int i=0;i<tamanho_matriz;i++){
            for(int j=0;j<tamanho_matriz;j++){
            arqrintf(arq, "< %d, %d, %d > ", matriz_final[i][j].R, matriz_final[i][j].G, matriz_final[i][j].B);
            }
        if(i != tamanho_matriz)
            arqrintf(arq, "\n");
        }
    }
    fclose(arq);
  }
  MPI_Finalize();//Finaliza o MPI
  fim = MPI_Wtime();//Para o cronometro
  printf("Processo %d, tempo gasto: %f\n", id_processo, fim-ini); //Exibe o tempo de cada processo

  return 0;
}

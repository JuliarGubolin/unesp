//Inserção das bibliotecas
#include<stdio.h>
#include<stdlib.h>
//Estrutura que recebe as informações necessárias de cada mês de 1 a 12
typedef struct month{
  int qtd; //Recebe quantas vezes o mês foi encontrado no arquivo para ser calculada a média das médias, a média das mínimas e a média das máximas
  float media, minima, maxima, maior, menor;
}Mes;
//Subprograma para somar os valores recebidos da média, máxima e mínima, além de
//calcular o maior e o menor valor de temperatura naquele mês
void calcular_media_maxima_minima(float maxima, float minima, float media, Mes *dados){
    dados->qtd++;
    if(dados->qtd == 1){
        dados->maior = maxima;
        dados->menor = minima;
    }else{
      if(maxima > dados->maior){
        dados->maior = maxima;
      }
      if(minima < dados->menor){
        dados->menor = minima;
      }
    }
    dados->minima = (minima + dados->minima); 
    dados->maxima = (maxima + dados->maxima);
    dados->media = (media + dados->media); 
}
//Subprograma para, ao final, dividir os valores e calcular suas médias, baseado na quantidade
//de vezes que um determinado mês apareceu no arquivo
void medias_finais(Mes *dados){
    dados->media = (dados->media)/dados->qtd;
    dados->maxima = (dados->maxima)/dados->qtd;
    dados->minima = (dados->minima)/dados->qtd;
}
//Função principal
int main(void){
  //Variáveis
  //Cada posição do vetor de struct representa um mês
  Mes dados[12];
  //Ponteiros para os arquivos de leitura e escrita
  FILE *arqRead, *arqWrite;
  //Variáveis para receber valores e controlar loops
  int ano, mes, i=0;
  float media=0, minima=0, maxima=0;
  //Inicializando vetor com o valor 0
  while(i<12){
    dados[i].qtd = 0;
    dados[i].minima=dados[i].maxima=dados[i].media=dados[i].menor=dados[i].maior=0.0;
    i++;
  }
  //Verificando os arquivos para abertura correta
  if((arqRead = fopen("temps.dat", "r")) == NULL || (arqWrite = fopen("medias.dat", "w")) == NULL){
      printf("Erro na abertura do(s) arquivo(s).");
      exit(1);
  }
  //Enquanto houver dados no arquivo, cada linha será armazenada na variável correspondente ao seu significado
  //e, a partir do mês indicado no arquivo, a posição que o representa no vetor será atualizada
  while(!feof(arqRead)){
    fscanf(arqRead, "%d %d %f %f %f", &ano, &mes, &minima, &media, &maxima);
    calcular_media_maxima_minima(maxima, minima, media, &dados[mes-1]);
  }
  //Zerar a variável i para iniciar o próximo loop
  i=0;
  //Loop para calcular as médias finais (dividir os valores pela quantidade) e escrever no arquivo com
  //a formatação: mês médiaMínima (mínima) médiaMédias médiaMáximas (máxima)
  while(i<12){
    medias_finais(&dados[i]);
    fprintf(arqWrite, "%d %.1f (%.1f) %.1f %.1f (%.1f)\n", i+1, dados[i].minima, dados[i].menor, dados[i].media, dados[i].maxima, dados[i].maior);
    i++;
  }
  //Mensagem para o usuário
  printf("Arquivo analisado com sucesso. Verifique a saída no arquivo 'medias.dat'.\n");
  //Finaliza o programa fechando ambos os arquivos de leitura e escrita
  fclose(arqRead);
  fclose(arqWrite);
  return 0;
}
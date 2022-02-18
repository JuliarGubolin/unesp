//Inserção das bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Função principal
int main(void){
  //Declarações
  //Ponteiros para os arquivos: barras.dat e codigos.dat
  FILE *arqRead, *arqWrite;
  //Variáveis 
  int i=0, j=0, contadorzeros=0, qtduns=0, qtdzeros=0, qtdColUm=0, qtdColZero=0, decode[48], contNumLidos=0, contTotCod=0, contadorLinhas=0, cont=0, aux=0, contador=0;
  //Variável que irá armazenar os caracteres do arquivo
  char cod;
  //Verificando se ambos os arquivos estão corretos para a abertura
  if((arqRead = fopen("barras.dat", "r")) == NULL || (arqWrite = fopen("codigos.dat", "w")) == NULL){
      printf("Erro na abertura do arquivo.");
      exit(1);
  }
  //Contando quantos códigos de 3 linhas tem no arquivo para criar o loop abaixo
  //A cada zero lido, uma linha é pulada e a variável cont, responsável por contar quantos códigos tem, é incrementada.
  while ((cod = fgetc(arqRead)) != EOF)
  { 
    cod = fgetc(arqRead);
    if(cod == '0'){
      while(cod != '\n'){
        cod = fgetc(arqRead);
          if(cod == '\n'){
            cont++;
          }
       }
     }
   }
   //Temos que dividir por 3 para obter o número de códigos no arquivo
   contador = cont/3;
   //Retornando o ponteiro para o início do arquivo
   rewind(arqRead);
   //Iniciando a análise do arquivo e conversão dos códigos
   while(aux != contador){
    cod=fgetc(arqRead);
    //Loop para encontrar o primeiro zero, ou seja, o primeiro código depois 
    //de uma sequência indeterminada de uns
    while(cod != '0'){
      cod=fgetc(arqRead);
    }
    //Quando encontra 1 zero, verifica como deve ser a contagem dos valores.
    //Ex: se a variável contadorezeros receber 2, a cada dois valores iguais na sequência, temos um único valor para converter depois.
    while(cod == '0'){
      contadorzeros++;
      cod=fgetc(arqRead);
    }
    //Pulando os demais valores iniciais até o início do código de fato
    fseek(arqRead, (contadorzeros*2), SEEK_CUR);
    //Este loop garante que serão lidos 12 números no total em cada código
    while(contTotCod < 12){
      //Este loop é utilizado para ler 6 valores, pular o centro (não é valor para converter), e ler novamente mais 6 valores
      while(contNumLidos < 6){
        //Cada valor a ser convertido é representado por duas colunas de zeros e duas de uns. 
        //Este loop garante que cada valor decimal de 0 a 9 seja composto por 4 valores entre 0 e 4, que serão convertidos posteriormente
        while(qtdColUm < 2 && qtdColZero < 2){
          //No início do código, a leitura deve se iniciar do 1. Porém, 
          //quando passamos dos 6 primeiros números, a contagem se inicia do 0.
          if(contTotCod == 6){
            //Caso ele encontre um zero, ele irá contar quantos são um a um e, ao final, dividir esse
            //valor pelo número de zeros encontrado no início da leitura do código.
            //Após isso, o valor encontrado é salvo na posição i do vetor decode[i]
            if(cod == '0'){
              while(cod=='0'){
                qtdzeros++;
                cod=fgetc(arqRead);
              }
              qtdzeros = qtdzeros/contadorzeros;
              qtdColZero++;
              decode[i] = qtdzeros;
              i++;
              qtdzeros = 0;
            }
            if(cod == '1'){
              while(cod=='1'){
                qtduns++;
                cod=fgetc(arqRead);
              }
              qtduns = qtduns/contadorzeros;
              decode[i] = qtduns;
              i++;
              qtdColUm++;
              qtduns = 0;
             }
          //Ainda no início do código
          }else{
            if(cod == '1'){
              while(cod=='1'){
                qtduns++;
                cod=fgetc(arqRead);
              }
              qtduns = qtduns/contadorzeros;
              decode[i] = qtduns;
              i++;
              qtdColUm++;
              qtduns = 0;
            }
            if(cod == '0'){
              while(cod=='0'){
                qtdzeros++;
                cod=fgetc(arqRead);
              }
              qtdzeros = qtdzeros/contadorzeros;
              qtdColZero++;
              decode[i] = qtdzeros;
              i++;
              qtdzeros = 0;
            }
          }
        }
        //Zerando os valores para se iniciar uma nova contagem de numero
        qtdColUm = 0;
        qtdColZero = 0;
        //Armazena a quantidade de números lidos até o momento
        contNumLidos++;
      }
        contNumLidos=0;
        contTotCod = contTotCod + 6;
        // Pula o centro dos códigos, o qual não é um número a ser convertido e seu tamanho é sempre 
        //a quantidade de zeros vezes 5
        while(j < (contadorzeros*5)){
          cod=fgetc(arqRead);
          j++;
        }
      }
    //Neste loop, ocorre a conversão dos valores do vetor para os decimais correspondentes.
    //A cada 4 posições no vetor, temos 1 numero para ser convertido para decimal, //assim que o valor é encontrado, já é escrito no arquivo.
    //Ao final, ocorre uma quebra de linha para garantir que cada código converido
    //ocupe uma linha do arquivo
    for(i=0;i<48;i+=4){
        //Ex: se decode[0] == 3 && decode[1] == 2 && decode[2] == 1 && decode[3] == 1
        //Escreve no arquivo o decimal correspondente, neste caso o 0. 
        if(decode[i] == 3 && decode[i+1] == 2 && decode[i+2] == 1 && decode[i+3] == 1){
          fprintf(arqWrite, "%d ", 0);
        }else if(decode[i] == 2 && decode[i+1] == 2 && decode[i+2] == 2 && decode[i+3] == 1){
          fprintf(arqWrite, "%d ", 1);
        }else if(decode[i] == 1 && decode[i+1] == 4 && decode[i+2] == 1 && decode[i+3] == 1){
          fprintf(arqWrite, "%d ", 3);
        }else if(decode[i] == 1 && decode[i+1] == 1 && decode[i+2] == 3 && decode[i+3] == 2){
          fprintf(arqWrite, "%d ", 4);
        }else if(decode[i] == 2 && decode[i+1] == 1 && decode[i+2] == 2 && decode[i+3] == 2){
          fprintf(arqWrite, "%d ", 2);
        }else if(decode[i] == 1 && decode[i+1] == 2 && decode[i+2] == 3 && decode[i+3] == 1){
          fprintf(arqWrite, "%d ", 5);
        }else if(decode[i] == 1 && decode[i+1] == 1 && decode[i+2] == 1 && decode[i+3] == 4){
          fprintf(arqWrite, "%d ", 6);
        }else if(decode[i] == 1 && decode[i+1] == 3 && decode[i+2] == 1 && decode[i+3] == 2){
          fprintf(arqWrite, "%d ", 7);
        }else if(decode[i] == 1 && decode[i+1] == 2 && decode[i+2] == 1 && decode[i+3] == 3){
          fprintf(arqWrite, "%d ", 8);           
        }else{
          fprintf(arqWrite, "%d ", 9);
        }
    }
    //Pula para a próxima linha após inserir um código
    fprintf(arqWrite, "\n");
    cont=0;
    //Pula as 2 linhas restantes do código atual para iniciar a leitura do outro
    while (cont < 3)
    {
      cod = fgetc(arqRead);
      if(cod == '\n'){
        cont++;
      }
    }
    //Incrementando a variável aux, que indica quantos códigos já foram lidos
    aux++;
    //Zerando as variáveis para iniciar uma leitura de um novo código
    contadorzeros=0;
    contTotCod = 0;
    contNumLidos = 0;
    qtdColUm=0;
    qtdColZero=0;
    i=0;
    j=0;
  }
  //Finaliza o programa fechando os arquivos e mostrando
  //mensagens ao usuário indicando sucesso.
  printf("Arquivo de entrada 'barras.dat' lido com sucesso. Verifique o arquivo de saída 'codigos.dat.'\n");
  fclose(arqRead);
  fclose(arqWrite);
  return 0;
}
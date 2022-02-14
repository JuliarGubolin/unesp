//Chamada de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//Chama do rquivo com todas as funções da árvore B e da manipulação de arquivo.
#include "arvore_b.h"
//Define uma ordem fixa para a paginação da árvore.
#define ORDEM 2
//Define um nome fixo para o arquivo de dados.
#define namefile "_arquivo.dat"

//Função para limpar o terminal. Auxilia na visualização.
void limpaTerminal(){
  system("clear");
}
//Início da função principal do programa.
int main(void){
  //Declaração: ponteiro "arv" do tipo Apontador.
  Apontador *arv;
  //Declaração: variável reg do tipo Registro
  Registro reg;
  /*Declarações: doi[20], do tipo string, para receber o DOI
  digitado pelo usuário.
  int i e num=0 para o loop da impressão dos dados na tela.
  op para receber a opção do menu digitada pelo usuário.
  */
  char doi[20];
  int i, num = 0, op;
  //Criando um ponteiro chamado "arv" do tipo Apontador . 
  arv=(Apontador*) malloc(sizeof(Apontador));
  //Criando um ponteiro chamado "LISTA" do tipo node.
  node *LISTA = (node *) malloc(sizeof(node));
  Inicializa(arv);
  inicia(LISTA);	
  //Verificação: se o arquivo existe, recupera os dados nele escritos.
  if (file_exists(namefile)){
    recuperarReg(arv, LISTA);
  }
    limpaTerminal();
    //Início do MENU principal para interação com o usuário
  do{
    printf("-------------------------------------\n");
    printf("1. Inserir no arquivo\n2. Remover do arquivo\n3. Buscar no arquivo\n4. Imprime arquivo\n5. Alterar registro\n6. Sair");
    printf("\n-------------------------------------\n");
    printf("-> ");
    scanf("%d", &op);
    switch(op){
      //Opção 1: Inserir uma referência bibliográfica no arquivo de dados.
      case 1:
      /*Para cadastrar uma referência bibliográfica, são necessárias as informações:
      1. DOI
      2. Sobrenome
      3. Nome
      4. Título da obra
      5. Local
      6. Editora
      7. Edição
      8. Ano de Publicação*/
        limpaTerminal();
        printf("INSERÇÃO\n");
        printf("DOI: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", reg.DOI);
        printf("Sobrenome: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", reg.sobrenome);
        setbuf(stdin, NULL);
        printf("Nome: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", reg.nome);
        setbuf(stdin, NULL);
        printf("Título da obra: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", reg.titulo);
        printf("Local de publicação: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", reg.local);
        setbuf(stdin, NULL);
        printf("Editora: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", reg.edit);
        printf("Edição: ");
        setbuf(stdin, NULL);
        scanf("%d", &reg.ed);
        setbuf(stdin, NULL);
        printf("Ano de publicação: ");
        scanf("%d", &reg.ano);
        count++;
        reg.rank = count;
        setbuf(stdin, NULL);
        //Chamada de função: Função insere do arquivo "arvore_b.h"
        Insere(reg,arv);
        break;
        //Opção 2: Remove uma referência bibliográfica do arquivo de dados.
      case 2:
        limpaTerminal();
        printf("REMOÇÃO\n");
        //Usuário deve inserir o DOI do registro que deseja remover.
        printf("Digite o DOI para remover: ");
        scanf("%s", doi);
        strcpy(reg.DOI,doi);
        Retira(reg.DOI, arv);
        remove(namefile);
			  saveAux(*arv,2*ORDEM);
        break;
        //Opção 3: Busca uma referência bibliográfica pelo índice primário DOI
      case 3:
        getchar();
        limpaTerminal();
        printf("BUSCA\n");
        //Usuário deve inserir o DOI do registro que deseja buscar.
        printf("Digite o DOI para busca: ");
        scanf("%s", doi);
        strcpy(reg.DOI,doi);
        Busca(reg,*arv);
        break;
        //Opção 4: Imprime os nós, os apontadores e os DOI's correspondentes de cada registro do arquivo.
      case 4:
        for(i=0; i < 2*ORDEM; i++){
		  	  num = Imprime2(*arv, i, 0, num);
        }
        break;
        //Opção 5: Altera uma referência bibliográfica já inserida no arquivo. Mantém na mesma posição.
      case 5:
        limpaTerminal();
        printf("ALTERAÇÃO\n");
        //Usuário deve inserir o DOI do registro que deseja remover.
        printf("Digite o DOI para alterar: ");
        scanf("%s", doi);
        alterarReg2(reg.DOI, arv);
        remove(namefile);
			  saveAux(*arv,2*ORDEM);
        break;
        //Opção 6: Fecha a aplicação.
      case 6:
        limpaTerminal();
        printf("Saindo...\n");
        break;
        //Verificação: Caso o usuário digite alguma opção que não as anteriores.
      default:
      limpaTerminal();
        printf("Opção inválida. Leia Novamente o menu.\n");
        break;
    }
  }while(op!=6);
  setbuf(stdin, NULL);
  //FIM
  return  0;
}
#include <stdio.h>
#include <stdlib.h>

//TAD Lista
typedef struct Lista{
    int info;
    struct Lista *prox;
}lista;

//Operações
void inserir(lista **L, int x);
void remover(lista **L, int x);
void imprimir(lista *L);
void limpa_terminal();

int main(void){

    lista *P = NULL;
    int op, valor, aux=0, p=0;
    //Fazer menu
    while(op != 4){
        printf("-------------\n");
        printf("1 - Inserir\n2 - Remover\n3 - Mostrar\n4 - Sair\n");
        printf("-------------\n");
        printf("-> ");
        scanf("%d", &op);
        switch (op){
            case 1:
                limpa_terminal();
                printf("Valor para inserir: ");
                scanf("%d", &valor);
                inserir(&P, valor);
                break;
            case 2: 
                limpa_terminal();
                printf("Valor para remover: ");
                scanf("%d", &valor);
                remover(&P, valor);
                break;
            case 3:
                limpa_terminal();
                imprimir(P);
                break;
            case 4:
                limpa_terminal();
                printf("Saindo...\n");
                break;
            default:
                limpa_terminal();
                printf("Opção inválida. Leia novamente o menu.\n");
                break;
        }
    }
    return 0;
}
void limpa_terminal(){
    system("clear");
}
//Implementações
//Inserir de forma ordenada
void inserir(lista **L, int x){
    lista *novo, *aux, *aux_ant;

    //Criar Novo elemento
    novo = (lista *)malloc(sizeof(lista));
    novo->info = x;
    if((*L) == NULL){ //Lista vazia
        (*L) = novo;
        printf("Inserido.\n");
    }else{
        aux = (*L);
        aux_ant = NULL;
        //Movimentar o aux
        while(aux != NULL && x> aux->info){ //Encontrar a posição
            aux_ant = aux;
            aux = aux->prox;
        }
        //Inserção
        if(aux_ant == NULL){ //Início
            novo->prox = aux;
            (*L) = novo;
        }
        else{ //Meio e fim
            aux_ant->prox = novo;
            novo->prox = aux;
        }
        printf("Inserido.\n");
    }
}
//Remove um elemento escolhido pelo usuário
void remover(lista **L, int x){
    lista *aux, *aux_ant;
    if((*L) == NULL){
        printf("Lista vazia.\n");
    }
    else{
        aux = (*L);
        aux_ant = NULL;
        while(aux != NULL && x> aux->info){ //Encontrar a posição
            aux_ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL){//Elemento não encontrado
            printf("Elemento não encontrado.\n");
        }
        else{
            if(aux_ant == NULL){//Início
                (*L) = aux->prox;
                free(aux);
                printf("Elemento excluido.\n");
            }
            else{ //Meio ou fim
                aux_ant->prox = aux->prox;
                free(aux);
                printf("Elemento excluido.\n");
            }
        }
    }
}
//Mostra a lista ordenada para o usuário
void imprimir(lista *L){
    lista *aux;
    aux = L;
    if(aux == NULL){
        printf("Lista vazia.\n");
    }
    else{
        printf("Lista: ");
        while(aux != NULL){
            printf("|%d| -> ", aux->info);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
}

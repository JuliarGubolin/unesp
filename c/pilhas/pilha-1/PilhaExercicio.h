#include <stdio.h>
#include <stdlib.h>

//Tad pilha
typedef struct Pilha{
    int info;
    struct Pilha *prox;
}pilha;

//Operações
pilha *criar_pilha(void);
pilha *push(pilha *P, int x);
pilha *pop(pilha *P);
void imprimir(pilha *P);

//Implementação
pilha *criar_pilha(void){
    return NULL;
}
//Inserir na pilha
pilha *push(pilha *P, int x){
    pilha *novo, *aux, *aux_ant;
    //Criar Novo elemento
    novo = (pilha *)malloc(sizeof(pilha));
    novo->info = x;
    if(P == NULL){ 
        novo->prox = NULL;
        printf("Inserido.\n");
        return novo;
    }
    else{
        novo->prox = P;
        P = novo;
    }
    return P;
}
//Remove um elemento escolhido pelo usuário
pilha *pop(pilha *P){
    pilha *aux;
    if(P == NULL){
        printf("Pilha vazia. Não há elementos para excluir.\n");
    }
    else{
        aux = P;
        P = P->prox;
        aux->prox = NULL;
        printf("Elemento %d removido.\n", aux->info);
        free(aux);
    }
    return P;
}
//Mostra a pilha ordenada para o usuário
void imprimir(pilha *P){
    pilha *aux;
    aux = P;
    if(P == NULL){
        printf("Pilha vazia.\n");
    }
    else{
        printf("Pilha: ");
        while(aux != NULL){
            printf("|%d| -> ", aux->info);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
}

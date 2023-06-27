#include <stdio.h>
#include <stdlib.h>

//Tad pilha
typedef struct Pilha{
    ABB *key;
    struct Pilha *prox;
}pilha;

//Operações
pilha *criar_pilha(void);
pilha *push(pilha *P, ABB* x);
pilha *pop(pilha *P);
void mostrar(pilha *P);

//Implementação
pilha *criar_pilha(void){
    return NULL;
}
//Inserir na pilha
pilha *push(pilha *P, ABB* x){
    pilha *novo, *aux, *aux_ant;
    novo = (pilha *)malloc(sizeof(pilha));
    novo->key = x;
    printf("Key->info: %c\n", novo->key->val);
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
        printf("Elemento %c removido.\n", aux->key->val);
        free(aux);
    }
    return P;
}
//Mostra a pilha ordenada para o usuário
void mostrar(pilha *P){
    pilha *aux;
    aux = P;
    if(P == NULL){
        printf("Pilha vazia.\n");
    }
    else{
        printf("Pilha: ");
        while(aux != NULL){
            printf("|%c| -> ", aux->key->val);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
}

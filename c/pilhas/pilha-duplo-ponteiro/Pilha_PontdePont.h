#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *prox;
}pilha;

void insere(pilha **q, int x);
void imprime(pilha *q);
void remover(pilha **q);

void insere(pilha **q, int x){

    pilha *novo;
    novo = (pilha *)malloc(sizeof(pilha));
    novo->info = x;
    novo->prox = NULL;
    if((*q) == NULL){
        (*q) = novo;
    }else{
        novo->prox = (*q);
        (*q) = novo;
    } 
    printf("Elemento %d inserido.\n", x);
}

void remover(pilha **q){

    pilha *temp;
    int var;
    if((*q) == NULL){
        printf("Pilha vazia.\n");
    }else{
        temp = (*q);
        var = temp->info;
        (*q) = temp->prox;
        temp->prox = NULL;
        free(temp);
    }
    printf("Elemento %d removido.\n", var);
}
void imprime(pilha *q){
    pilha *aux;
    aux = q;
    if(aux == NULL){
        printf("Pilha vazia.\n");
    }else{
        while (aux != NULL){
            printf("%d - ", aux->info);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
}

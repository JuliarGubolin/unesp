#include <stdio.h>
#include <stdlib.h>

//Tad fila
typedef struct Fila{
    int info;
    struct Fila *prox;
}fila;

typedef struct ponteiros{
    fila *ini;
    fila *fim;
}pont;

//Operações
pont *criar_ponteiros();
void inserir(pont *Q, int x);
void remover(pont *Q);
void imprimir(pont *Q);

//Implementação
pont *criar_ponteiros(){
    pont *Q;
    Q = malloc(sizeof(pont));
    Q->ini = Q->fim = NULL;
    return Q;
}
//Inserir na fila
void inserir(pont *Q, int x){
    fila *novo, *aux, *aux_ant;
    //Criar Novo elemento
    novo = (fila *)malloc(sizeof(fila));
    novo->info = x;
    if(Q->ini == NULL){ 
        novo->prox = NULL;
        Q->ini = Q->fim = novo;
        printf("Inserido.\n");
    }
    else{
        Q->fim->prox = novo;
        novo->prox = NULL;
        Q->fim = novo;
    }
}
//Remove o primeiro elemento da fila
void remover(pont *Q){
    fila *aux;
    if(Q->ini == NULL){
        printf("Fila vazia. Não há elementos para excluir.\n");
    }
    else{
        aux = Q->ini;
        Q->ini = Q->ini->prox;
        aux->prox = NULL;
        printf("Elemento %d removido.\n", aux->info);
        free(aux);
    }
}
//Mostra a fila ordenada para o usuário
void imprimir(pont *Q){
    fila *aux;
    aux = Q->ini;
    if(Q->ini == NULL){
        printf("Fila vazia.\n");
    }
    else{
        printf("Fila: ");
        while(aux != NULL){
            printf("|%d| -> ", aux->info);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
}
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
//FILA.C
#include <stdio.h>
#include <stdlib.h>
#include "FilaExercicio.h"

void limpa_terminal();

int main(void){

    int op=0, val=0;
    //fila *F = criar_fila();
    pont *Q = criar_ponteiros();
    do{
        printf("----FILA----\n1 - Inserir\n2 - Remover\n3 - Imprimir Fila\n4 - Sair\n-------------\n-> ");
        scanf("%d", &op);
        switch(op){
            case 1:
                limpa_terminal();
                printf("Valor para inserir: ");
                scanf("%d", &val);
                inserir(Q, val);
                break;
            case 2:
                limpa_terminal();
                remover(Q);
                break;
            case 3:
                limpa_terminal();
                imprimir(Q);
                break;
            case 4:
                limpa_terminal();
                printf("Saindo...\n");
                break;
            default:
                limpa_terminal();
                printf("Opcao invalida. Leia novamente o menu.\n");
                break;    
        }
    }while(op != 4);
    return 0;
}
void limpa_terminal(){
    system("clear");
}

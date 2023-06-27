#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *prox;
}fila;

void insere(fila **q, int x);
void imprime(fila *q);
void remover(fila **q);
//Com ponteiro para ponteiro, temos a vantagem de não precisar retornar a Fila para a Main,
//podendo assim retornar outra variável.

int main(void){

    int x; 
    int op = 0;
    fila *Q = NULL;

    while(op != 4){
        printf("\nFila com Ponteiro para Ponteiro\n1 - Inserir\n2 - Imprimir\n3 - Remover\n4 - Sair\n-> ");
        scanf("%d", &op);
        switch (op){
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &x);
                insere(&Q, x); 
                break;
            case 2:
                imprime(Q);
                break;
            case 3:
                remover(&Q);
                break;
            case 4:
                printf("Saindo...\n");
                break;    
            default:
                printf("Opção Inválida.\n");
                break;
        }
    }
}
void insere(fila **q, int x){
    fila *aux, *novo;
    novo = (fila *) malloc(sizeof(fila));
    novo->info = x;
    novo->prox = NULL;

    if((*q) == NULL){
        (*q) = novo;
    }else{
        aux = (*q);

        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    printf("Inserido.\n");
}
void remover(fila **q){
    fila *temp;

    if((*q) == NULL){
        printf("Não existem elementos na fila.\n");
    }else{
        temp = (*q);
        (*q) = temp->prox;
        free(temp);
    }

}
void imprime(fila *q){
    fila *aux;

    aux = q;
    if(aux == NULL){
        printf("Fila vazia.\n");
    }else{
        while(aux != NULL){
            printf("|%d| - ", aux->info);
            
            aux = aux->prox;
        }
        printf("NULL");
    }
}
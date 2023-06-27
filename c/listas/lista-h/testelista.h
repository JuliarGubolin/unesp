#include <stdio.h>
#include <stdlib.h>

//Tad Lista
typedef struct Lista{
    int info;
    struct Lista *prox;
}lista;

//Operações
lista *criar_lista(void);
lista *inserir(lista *L, int x);
lista *remover(lista *L, int x);
void imprimir(lista *L);
int recuperar(lista *L, int p);
int localizar(lista *L, int x);

//Implementação
lista *criar_lista(void){
    return NULL;
}
//Inserir de forma ordenada
lista *inserir(lista *L, int x){
    lista *novo, *aux, *aux_ant;

    //Criar Novo elemento
    novo = (lista *)malloc(sizeof(lista));
    novo->info = x;
    if(L == NULL){ //Lista vazia
        novo->prox = NULL;
        system("clear");
        printf("Inserido.\n");
        return novo;
        //L já vai apontar para novo
    }else{
        aux = L;
        aux_ant = NULL;
        //Movimentar o aux
        while(aux != NULL && x> aux->info){ //Encontrar a posição
            aux_ant = aux;
            aux = aux->prox;
        }
        //Inserção
        if(aux_ant == NULL){ //Início
            novo->prox = aux;
            L = novo;
        }
        else{ //Meio e fim
            aux_ant->prox = novo;
            novo->prox = aux;
        }
        system("clear");
        printf("Inserido.\n");
        return L;
    }
}
lista *remover(lista *L, int x){
    lista *aux, *aux_ant;
    if(L == NULL){
        system("clear");
        printf("Lista vazia.\n");
    }
    else{
        aux = L;
        aux_ant = NULL;
        while(aux != NULL && x> aux->info){ //Encontrar a posição
            aux_ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL){//Elemento não encontrado
            printf("Valor não encontrado.\n");
            return L;
        }
        else{
            if(aux_ant == NULL){//Início
                L = aux->prox;
                free(aux);
                system("clear");
                printf("Elemento excluido.\n");
                return L;
            }
            else{ //Meio ou fim
                aux_ant->prox = aux->prox;
                free(aux);
                system("clear");
                printf("Elemento excluido.\n");
                return L;
            }
        }
    }
    return L;
}
void imprimir(lista *L){
    lista *aux;
    aux = L;
    if(L == NULL){
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
int recuperar(lista *L, int p){
    lista *aux, *aux_ant;
    int cont, aux3=0, aux2=0, c=0;
    aux = L;
    if(L == NULL){
        printf("Lista vazia.\n");
    }
    else{
        for(cont=0;cont<=p;cont++){
            aux = aux->prox;
            c++;
        }
        //Remover o único elemento de uma lista
        if(c==1){
            aux = L;
            aux3 = aux->info;
            aux2 = aux3;
            remover(L, aux3);
        }
        //Verifica se a posição digitada é válida
        c=0;
        else if(aux == NULL){
            printf("Posição não encontrada.\n");
            aux2 = 0;
        }
        else{
            aux = aux->prox;
            aux3 = aux->info;
            aux2 = aux3;
            remover(L, aux3);
        }    
    }
    return aux2;
}
int localizar(lista *L, int x){
    lista *aux;
    int cont=1;
    aux = L;
    if(L == NULL){
        printf("Lista Vazia.\n");
    }
    while(aux != NULL && x != aux->info){
            cont++;
            aux = aux->prox;
    }
    if(aux == NULL){
        printf("Elemento não encontrado.\n");
        cont = 0;
    }
    return (cont);
}
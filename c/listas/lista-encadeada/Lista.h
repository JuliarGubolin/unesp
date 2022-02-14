#include <stdio.h>
#include <stdlib.h>

//TAD Lista
typedef struct Lista{
    int info;
    struct Lista *prox;
}lista;

//Operações
lista *criar_lista(void);
lista *inserir(lista *L, int x);
lista *remover(lista *L, int x);
void imprimir(lista *L);
lista *recuperar(lista *L, int p);
int localizar(lista *L, int x);

//Implementações
//Cria a lista
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
        printf("Inserido.\n");
        return L;
    }
}
//Remove um elemento escolhido pelo usuário
lista *remover(lista *L, int x){
    lista *aux, *aux_ant;
    if(L == NULL){
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
            printf("Elemento não encontrado.\n");
            return L;
        }
        else{
            if(aux_ant == NULL){//Início
                L = aux->prox;
                free(aux);
                printf("Elemento excluido.\n");
                return L;
            }
            else{ //Meio ou fim
                aux_ant->prox = aux->prox;
                free(aux);
                printf("Elemento excluido.\n");
                return L;
            }
        }
    }
    return L;
}
//Mostra a lista ordenada para o usuário
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
//Recuperar e Localizar consideram a primeira posição como sendo 0, como em um vetor.
lista *recuperar(lista *L, int p){
    lista *aux;
    aux = L;
    int cont=0, x=0;
    while(aux != NULL && cont<p){
        cont++;
        aux = aux->prox;
    }
    if(aux == NULL || p<0){
        printf("Posição não encontrada/inválida.\n");
    }
    else{
        x = aux->info;
        L = remover(L, x);
        printf("Elemento %d removido.\n", x);
    }
    return L;
}
/*lista *recuperar(lista *L, int p){
    lista *aux, *aux_ant;
    aux = L;
    aux_ant = NULL;
    int cont, aux3=0, aux2=0;
    for(cont=0;cont<p;cont++){
        aux_ant = aux;
        aux = aux->prox;
    }
    aux = aux_ant;
    aux3 = aux->info;
    printf("Elemento %d excluído.\n", aux3);
    remover(L, aux3);    
    return L;
}*/
int localizar(lista *L, int x){
    lista *aux;
    int cont=0;
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
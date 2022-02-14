#include <stdio.h>
#include <stdlib.h>

//TAD Lista
typedef struct Lista{
    int info;
    struct Lista *prox;
    struct Lista *ant;
}lista;

//Operações
lista *criar_lista(void);
lista *inserir(lista *C ,int x);
lista *remover(lista *C, int x);

//Implementações
//Cria a lista
lista *criar_lista(void){
    return NULL;
}
//Inserir de forma ordenada na lista circular
//C indica o início da lista (menor valor)
lista *inserir(lista *C ,int x){
    lista *novo, *aux;

    novo = (lista *)malloc(sizeof(lista));
    novo->info = x;
    if(C == NULL){ 
        novo->prox = novo;
        novo->ant = novo;
        return novo;
    }
    else{
        //Insere no inicio ou fim
        if(x<C->info || x>(C->prox)->info){
            novo->prox = C;
            novo->ant = C->ant;
            C->ant = novo;
            C->ant->prox = novo;
            if(x>C->info){
                C = novo;
            }
        }
        //Insere no meio
        else{
            aux = C;
            do{
                aux = aux->prox;
            }while(aux != C && x>aux->info);
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
        }
        return C;
    }
}
//Remove um elemento escolhido pelo usuário
lista *remover(lista *C, int x){
    lista *aux, *temp;
    //Verifica se a lista está vazia
    if(C == NULL){
        printf("Lista Circular vazia.\n");
    }
    else{
        //Remove do inicio
        if(x == C->info){
            aux = C;
            C = C->prox;
            aux->ant->prox = C;
            C->ant = aux->ant;
            free(aux);
        }
        //Remove do final
        else if(x == C->ant->info){
            aux = C->ant;
            aux->ant->prox  = C;
            C->ant = aux->ant;
            free(aux);
        }
        //Remove do meio
        else{
            aux = C;
            do{
                aux = aux->prox;
            }while(aux != C && x != aux->info);
            if(aux == C){
                printf("Elemento não encontrado.\n");
            }
            else{
                temp = aux;
                aux = aux->prox;
                aux->ant = temp->ant;
                temp->ant->prox = aux;
                free(temp);
            }
        }
    }
    return C;
}

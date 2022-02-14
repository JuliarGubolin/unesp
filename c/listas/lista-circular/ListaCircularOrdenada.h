#include <stdio.h>
#include <stdlib.h>

//TAD Lista
typedef struct Lista{
    int info;
    struct Lista *prox;
    struct Lista *ant;
}lista;

//Estrutura com os ponteiros para o início e fim da lista
typedef struct Ponteiros{
    lista *ini;
    lista *fim;
}p;

//Operações
p *criar_ponteiros(void);
void inserir(p *C ,int x);
void remover(p *C, int x);
void imprimir(p *C);

//Implementações
//Cria a lista
p *criar_ponteiros(){
    p *C;
    C = malloc(sizeof(p));
    C->ini = NULL;
    C->fim = NULL;
    return C;
}
//Inserir de forma ordenada na lista cricular
void inserir(p *C, int x){
    lista *novo, *aux;

    novo = (lista *)malloc(sizeof(lista));
    novo->info = x;
    if(C->ini == NULL){ 
        novo->prox = novo;
        novo->ant = novo;
        C->ini = novo;
        C->fim = novo;
    }
    else{
        //Insere entre o inicio e o fim
        if(x>C->fim->info || x<C->ini->info){
            novo->prox = C->ini;
            novo->ant = C->fim;
            C->fim->prox = novo;
            C->ini->ant = novo;
            //Verifica se o valor deve ser o novo início ou o novo fim
            if(x>C->fim->info){
                C->fim = novo;
            }
            else{
                C->ini = novo;
            }
        }
        else{
            aux = C->ini;
            do{
                aux = aux->prox;
            }while(aux != C->ini && x>aux->info);
            //Insere no meio
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
        }
    }
}
//Remove um elemento escolhido pelo usuário
void remover(p *C, int x){
    lista *aux, *temp;
    int cont=0;
    aux = C->ini;
    //Verifica se a lista possui um único elemento e este será removido
    do{
        cont++;
        aux = aux->prox;
    }while(aux != C->fim->prox);
    if(cont == 1 && x == aux->info){
        free(aux);
        C->ini = C->fim = NULL;
    }
    else{
        //Verifica se a lista está vazia
        if(C->ini == NULL){
            printf("Lista Circular vazia.\n");
        }
        else{
            if(x == C->ini->info){
                aux = C->ini;
                C->ini = C->ini->prox;
                C->ini->ant = C->fim;
                C->fim->prox = C->ini;
                free(aux);
            }
            else if(x == C->fim->info){
                aux = C->fim;
                C->fim = C->fim->ant;
                C->ini->ant = C->fim;
                C->fim->prox = C->ini;
                free(aux);
            }
            else{
                aux = C->ini;
                do{
                    aux = aux->prox;
                }while(aux != C->ini && x != aux->info);
                if(x == aux->info){
                    temp = aux;
                    aux = aux->prox;
                    aux->ant = temp->ant;
                    temp->ant->prox = aux;
                    free(temp);
                }
                else{
                    printf("Elemento não encontrado.\n");
                }
                aux = NULL;
            }
        }
    }
}
void imprimir(p *C){

    lista *aux;
    if(C->ini == NULL){
        printf("Lista circular vazia.\n");
    }
    else{
        aux = C->ini;
        printf("Lista circular: ");
        do{
            printf("|%d| -> ", aux->info);
            aux = aux->prox;
        }while(aux != C->fim->prox);
        printf("NULL\n");
    }
}

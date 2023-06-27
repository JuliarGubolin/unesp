#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD Árvore Binária
typedef struct node{
    char val;
    struct node *esq, *dir;
}ABB;

//Operações
ABB *criar(void);
void imprimir(ABB *r);
//Inserir iterativo
ABB *inserir_iterativo(ABB *r, ABB *novo);

ABB *criar(void){
    return NULL;
}
//Imprime a árvore
void imprimir(ABB *r){ 
    if(r != NULL){
        printf("%c", r->val);
        printf("(");
        imprimir(r->esq);
        imprimir(r->dir);
        printf(")");
    }
}
//Inserir iterativo
ABB *inserir(ABB *r, ABB *novo){
    if(r == NULL){
        system("clear");
        printf("Elemento inserido!\n");
        return novo;
    }else{
        if(strcmp(novo->val,r->val) > 0){
            r->dir = inserir(r->dir, novo);
        }

        if(strcmp(novo->val,r->val) < 0){
            r->esq = inserir(r->esq, novo);
        }

        if(strcmp(novo->val,r->val) == 0){
            system("clear");
            printf("Elemento duplicado!\n");

            return r;
        }
    }

    system("clear");
    printf("Elemento inserido!\n");

    return r;
}
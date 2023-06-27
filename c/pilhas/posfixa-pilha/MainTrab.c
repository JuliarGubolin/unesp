#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "PilhaTrab.h"

int main(void){
    int x, cont, opcao=0, cont1;
    char exp[20];
	ABB *R, *novo, *novo1;
    pilha *P = criar_pilha();

    printf("Expressão pós-fixa: ");
    scanf("%s", &exp);

    for(x=0;x<strlen(exp);x++){
        if(strcmp(exp[x],"+") == 0 || strcmp(exp[x],"-") == 0|| strcmp(exp[x],"*") == 0 || strcmp(exp[x],"/") == 0){
            novo = P;
            P = pop(P);
            novo1 = P;
            P = pop(P);
            ABB *R3 = criar();
            R3->dir = novo;
            R3->esq = novo1;
            imprimir(R3);

        }else{
            R = criar();
            novo = (ABB *)malloc(sizeof(ABB));
            novo->val = exp[x];
            novo->dir = novo->esq = NULL;
            R = inserir_iterativo(R, novo);
            P = push(P, R);
            mostrar(P);
            imprimir(R);
        }
    }

    return 0;
}
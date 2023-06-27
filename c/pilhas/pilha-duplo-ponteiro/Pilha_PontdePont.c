#include<stdio.h>
#include<stdlib.h>
#include "Pilha_PontdePont.h"

int main(void){

    pilha *P = NULL;
    int op, val;
    while(op != 4){
        printf("\nPilha com Ponteiro para Ponteiro\n1 - Inserir\n2 - Imprimir\n3 - Remover\n4 - Sair\n-> ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Valor para inserir: ");
                scanf("%d", &val);
                insere(&P, val);
            break;
            case 2:
                imprime(P);  
            break;
            case 3:
                remover(&P);
            break;
            case 4:
                printf("Saindo...\n");
            break;
            default:
                printf("Opcao invalida.\n");
            break;
        }
    }



    return 0;
}
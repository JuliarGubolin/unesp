#include <stdio.h>
#include <stdlib.h>
#include "PilhaExercicio.h"

void limpa_terminal();

int main(void){

    int op=0, val=0;
    pilha *P = criar_pilha();
    do{
        printf("----PILHA----\n1 - Push\n2 - Pop\n3 - Imprimir Pilha\n4 - Sair\n-------------\n-> ");
        scanf("%d", &op);
        switch(op){
            case 1:
                limpa_terminal();
                printf("Valor para inserir: ");
                scanf("%d", &val);
                P = push(P, val);
                break;
            case 2:
                limpa_terminal();
                P = pop(P);
                break;
            case 3:
                limpa_terminal();
                imprimir(P);
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
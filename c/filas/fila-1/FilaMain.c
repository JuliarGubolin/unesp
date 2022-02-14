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

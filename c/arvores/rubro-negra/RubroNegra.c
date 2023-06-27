#include <stdio.h>
#include <stdlib.h>
#include "RubroNegra.h"

void limpa_terminal();

int main(void){

    RB *rb = inicializa_no();
    int op=0, val=0;
    do{
        printf("\n----ARVORE RUBRO NEGRA----\n1 - Inserir\n2 - Imprimir\n3 - Sair\n--------------------------\n-> ");
        scanf("%d", &op);
        switch(op){
            case 1:
                limpa_terminal();
                printf("Valor para inserir: ");
                scanf("%d", &val);
                RB *novo = criarNo(val);
                rb = inserir(rb, novo);
                rb->cor = 0;
                break;
            case 2:
                limpa_terminal();
                if(rb == NULL){
                    printf("Arvore Rubro Negra vazia.\n");
                }else{
                    imprimir(rb);
                }
                break;
            case 3:
                limpa_terminal();
                printf("Saindo...\n");
                break;
            default:
                limpa_terminal();
                printf("Opcao invalida. Leia novamente o menu.\n");
                break;    
        }
    }while(op != 3);
    return 0;
}
void limpa_terminal(){
    system("clear");
}
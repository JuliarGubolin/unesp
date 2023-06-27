#include <stdio.h>
#include <stdlib.h>
#include "AVL2.h"

void limpa_terminal();

int main(void){

    AVL *B = inicializa();
    int op=0, val=0;
    do{
        printf("\n----ARVORE AVL----\n1 - Inserir\n2 - Imprimir\n3 - Remover\n4 - Sair\n------------------\n-> ");
        scanf("%d", &op);
        switch(op){
            case 1:
                limpa_terminal();
                printf("Valor para inserir: ");
                scanf("%d", &val);
                AVL *novo = criarNo(val);
                B = inserir(B, novo);
                break;
            case 2:
                limpa_terminal();
                if(B == NULL){
                    printf("Arvore AVL vazia.\n");
                }else{
                    imprimir(B);
                }
                break;
            case 3:
                limpa_terminal();
                if(B == NULL){
                    printf("Arvore AVL vazia.\n");
                }else{
                    printf("Valor para ser removido: ");
                    scanf("%d", &val);
                    B = removerAVL(B, val);
                }
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
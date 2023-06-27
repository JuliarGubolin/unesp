#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include"Circular.h"

void limpa_terminal();
int main(void){

    setlocale(LC_ALL, "portuguese");
    lista *C = criar_lista();
    int op, valor, aux=0, p=0;
    //Fazer menu
    while(op != 3){
        printf("-------------\n");
        printf("1 - Inserir\n2 - Remover\n3 - Sair\n");
        printf("-------------\n");
        printf("-> ");
        scanf("%d", &op);
        switch (op){
            case 1:
                limpa_terminal();
                printf("Valor para inserir: ");
                scanf("%d", &valor);
                C = inserir(C, valor);
                printf("C->info: %d\n",C->info);
                printf("C->ant->info (Começo): %d\n",C->prox->info);
                break;
            case 2: 
                limpa_terminal();
                if(C == NULL){
                    printf("Lista vazia.\n");
                }else{
                    printf("Valor para remover: ");
                    scanf("%d", &valor);
                    C = remover(C, valor);
                }
                break;
            case 3:
                limpa_terminal();
                printf("Saindo...\n");
                break;
            default:
                limpa_terminal();
                printf("Opção inválida. Leia novamente o menu\n");
                break;
        }
    }
    return 0;
}
void limpa_terminal(){
    system("clear");
}